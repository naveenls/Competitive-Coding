#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[n];
	set<int> s;
	for(int i=0;i<n;i++)
		cin>>a[i],s.insert(a[i]);

	int ans[n];
	memset(ans,-1,sizeof(ans));
	
	for(int i=n-1;i>0;i--)
	{
		if(a[i]!=a[i-1])
		{
			ans[i]=a[i-1];
		}
	}
	int start=0;
	for(int i=0;i<n;i++)
	{
		while(s.find(start)!=s.end())
		{
			start++;
		}
		if(ans[i]==-1)
		{
			ans[i]=start;
			start++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
