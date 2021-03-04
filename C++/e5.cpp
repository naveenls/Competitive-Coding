#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,a,r,m;
	cin>>n>>a>>r>>m;
	
	long long arr[n+1];
	long long pre_sum[n+1];
	
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	
	pre_sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		pre_sum[i]=arr[i]+pre_sum[i-1];
	}
	long long min_cost=LONG_MAX;
	long long M=min(m,a+r);
	for(long long i=1;i<=n;i++)
	{
		long long cost=0;
		
		long long needed=i*arr[i]-pre_sum[i];
		long long extra=(pre_sum[n]-pre_sum[i])-(n-i)*arr[i];
		
		if(needed>extra)
		{
			cost+=extra*M;
			needed-=extra;
			cost+=needed*a;
		}
		else
		{
			cost+=needed*M;
			extra-=needed;
			cost+=extra*r;
		}

		min_cost=min(cost,min_cost);
	}
	
	long long val=pre_sum[n]/n;
	long long val1=(pre_sum[n]+n-1)/n;
	
	int ind=-1,ind1=-1;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]<=val)
		{
			ind=i;
		}
		if(arr[i]<=val1)
		{
			ind1=i;
		}
	}
	
	long long needed=val*ind-pre_sum[ind];
	long long extra=(pre_sum[n]-pre_sum[ind])-(n-ind)*val;
	long long cost=0;
	if(needed>extra)
	{
		cost+=extra*M;
		needed-=extra;
		cost+=needed*a;
	}
	else
	{
		cost+=needed*M;
		extra-=needed;
		cost+=extra*r;
	}
	
	min_cost=min(cost,min_cost);
	needed=val1*ind1-pre_sum[ind1];
	extra=(pre_sum[n]-pre_sum[ind1])-(n-ind1)*val1;
	cost=0;
	if(needed>extra)
	{
		cost+=extra*M;
		needed-=extra;
		cost+=needed*a;
	}
	else
	{
		cost+=needed*M;
		extra-=needed;
		cost+=extra*r;
	}
	min_cost=min(cost,min_cost);
	cout<<min_cost<<endl;
	return 0;
}
