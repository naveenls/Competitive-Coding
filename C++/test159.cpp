#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	
	string p,q;
	cin>>p>>q;
	
	int len1=p.size();
	int len2=q.size();
	
	int count[len2],next[len2];
	
	for(int i=0;i<len2;i++)
	{
		int start=i;
		int cnt=0;
		
		for(int j=0;j<len1;j++)
		{
			if(p[j]==q[start])
			{
				start++;
			}
			if(start==len2)
			{
				start=0;
				cnt++;
			}
		}
		
		count[i]=cnt;
		next[i]=start;
	}
	
	int i=0,j=0;
	
	int ans=0;
	
	while(i<a)
	{
		ans+=count[j];
		j=next[j];
		
		i++;
	}
	
	cout<<ans/b<<endl;
	return 0;
}

