#include<bits/stdc++.h>
using namespace std;

void change(int l,string &a)
{
	for(int j=0;j<=l;j++)
	{
		a[j]='1'-a[j] + '0';
	}
	
	int s=0,e=l;
	
	while(s<e)
	{
		swap(a[s],a[e]);
		s++;
		e--;	
	}
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		string a,b;
		
		cin>>a>>b;
		
		vector<int> ops;
		
		for(int i=n-1;i>0;i--)
		{
			if(a[i]!=b[i])
			{
				if(a[0]!=b[i])
				{
					ops.push_back(i);
					change(i,a);
				}
				else
				{
					ops.push_back(0);
					ops.push_back(i);
					change(i,a);
				}
			}
		}
		
		if(a[0]!=b[0])
		{
			ops.push_back(0);
		}
		
		cout<<ops.size()<<' ';
		for(auto ele:ops)
		{
			cout<<ele+1<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}
