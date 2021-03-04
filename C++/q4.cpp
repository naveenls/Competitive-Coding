#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,d,m;
	cin>>n>>d>>m;
	
	long long arr[n];
	long long s1=0;
	
	long long cnt=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
		if(arr[i]<=m)
			s1+=arr[i];
		else
			cnt++;
	}

	sort(arr,arr+n);
	
	long long sum[n];
	sum[0]=arr[0];
	
	for(int i=1;i<n;i++)
	{
		sum[i]=arr[i]+sum[i-1];
	}

	if(cnt==0)
	{
		cout<<sum[n-1]<<endl;
		return 0;
	}

	long long ma=0;
	for(long long i=1;i<=cnt;i++)
	{
		long long needed=i*(d+1)-cnt-d;
				
		if(needed>n)
		{
			continue;
		}
		
		if(needed>0)
		{
			if(arr[needed-1]<=m)
			{
				ma=max(ma,s1-sum[needed-1] + sum[n-1] - sum[n-i-1]);
			}
		}
		else
		{
			int extra=-needed;
			extra/=(d+1);
			
			if(n-extra-i-1>=0)
				ma=max(ma,s1+sum[n-1]-sum[n-i-extra-1]);
			else if(n-extra-i-1==-1)
				ma=max(ma,s1+sum[n-1]);

		}
	}
	
	cout<<ma<<endl;
	
	return 0;
}
