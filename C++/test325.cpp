#include<bits/stdc++.h>
using namespace std;

const int maxN=5*1e5;

long long arr[maxN];
int n;
long long k;

bool check(long long val)
{
	long long extra=0;
	long long needed=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]>val)
			extra+=(arr[i]-val);
		
		else
			needed+=(val-arr[i]);	
	}	
	
	if(extra>k)
		return false;
		
	if(extra<=needed)
		return true;
	else
	{
		cout<<1<<endl;
		exit(0);	
	}
}

long long check_min(long long val)
{
	long long needed=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<val)
			needed+=val-arr[i];
	}
	
	return needed;
}
long long find_max(long long val,long long extra)
{
	int l=0,r=val;
	int mi;
	
	while(l<=r)
	{
		long long mid=(l+r)/2;
		
		if(check_min(mid)<=extra)
		{
			mi=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}

	return mi;
}
long long find_diff(long long val)
{
	long long extra=0;
	
	for(int i=0;i<n;i++)
		if(arr[i]>val)
			extra+=arr[i]-val;
			
	long long mi=find_max(val,extra);
	
	return val-mi;
}
int main()
{
	cin>>n>>k;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	long long l=0,r=1e9;
	
	long long ans=0;
	
	while(l<=r)
	{
		long long mid=(l+r)/2;
		
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<find_diff(ans)<<endl;
	return 0;
}
