#include<bits/stdc++.h>
using namespace std;

long long mod=998244353;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int a[n],b[m];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	
	int mi[n];
	mi[n-1]=a[n-1];
	
	for(int i=n-2;i>=0;i--)
	{
		mi[i]=min(mi[i+1],a[i]);
		//cout<<mi[i]<<' ';
	}
	//cout<<endl;
	if(mi[0]!=b[0])
	{
		cout<<0<<endl;
		return 0;
	}
	
	long long start[m];
	memset(start,-1,sizeof(start));
	long long end[m];
	memset(end,-1,sizeof(end));
	
	start[0]=0;
	int j=0;
	
	for(int i=0;i<n;i++)
	{
		if(start[j]==-1)
		{
			if(mi[i]==b[j])
			{
				start[j]=i;
				end[j]=i;
			}
		}
		else
		{
			if(mi[i]==b[j])
			{
				end[j]=i;
			}
			else
			{
				j++;
				if(j<m && mi[i]==b[j])
				{
					start[j]=i;
					end[j]=i;
				}
			}
		}
	}
	
	for(int i=0;i<m;i++)
	{
		if(start[i]==-1 || end[i]==-1)
		{
			cout<<0<<endl;
			return 0;
		}
	}
		
	long long ans=1;
	/*
	for(int i=0;i<m;i++)
	{
		cout<<start[i]<<' '<<end[i]<<endl;
	}*/
	for(int i=1;i<m;i++)
	{
		ans=(ans*(long long)(end[i]-start[i]+1))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
