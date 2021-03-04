#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	int flag[n+1]={0};
	int first[n+1];
	int last[n+1];
	
	memset(first,-1,sizeof(first));
	
	int a;
	for(int i=0;i<k;i++)
	{
		cin>>a;
		flag[a]=1;
		
		if(first[a]==-1)
			first[a]=i;
		last[a]=i;
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			ans++;
			if(i>1)
			{
				ans++;
			}
			if(i<n)
			{
				ans++;
			}
			continue;	
		}
			
		if(i>1)
		{
			if(!flag[i-1])
				ans++;
			else
			{
				if(last[i-1]<first[i])
					ans++;
			}
		}
		if(i<n)
		{
			if(!flag[i+1])
				ans++;
			else
			{
				if(last[i+1]<first[i])
					ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
