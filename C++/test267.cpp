#include<bits/stdc++.h>
using namespace std;

int n,w;
long long m;

const int maxN=1e5;

long long arr[maxN+1];

bool check(long long val)
{
	long long inc[n+1]={0};
	
	for(int i=1;i<=n;i++)
	{
		long long new_val=arr[i] + inc[i-1] - inc[max(0,i-w)];
		if(new_val>=val)
		{
			inc[i]=0;
			inc[i]+=inc[i-1];
			continue;
		}
		inc[i]=val-new_val;
		inc[i]+=inc[i-1];
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<inc[i]<<' ';
	}*/
	if(inc[n]<=m)
		return true;
	
	return false;
}
int main()
{
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
		
	long long l=0,r=1e14;
	
	long long ans;
	
	while(l<=r)
	{
		long long mid=(l+r)/2;
		
		if(check(mid))
		{
			ans=mid;
			l=mid+1;	
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
