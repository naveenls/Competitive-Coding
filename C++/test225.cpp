#include<bits/stdc++.h>
using namespace std;

long long p=1e9+7;


long long find_sum(long long x)
{
	long long a=x;
	long long b=x+1;
	if(a%2)
	{
	    b/=2;
	}
	else
	{
	    a/=2;
	}
	return ((a%p)*(b%p))%p;
}
int main()
{
	long long n;
	cin>>n;
	
	long long ans=0;
	
	for(long long i=1;i*i<n;i++)
	{
		if(i==n/i)
			continue;
		
		ans=(ans+i*(n/i))%p;	
	}
	
	for(long long i=1;i*i<=n;i++)
	{
		long long end=n/i;
		long long start=n/(i+1);
		
		long long sum=(find_sum(end)-find_sum(start)+p)%p;
		
		ans=(ans+sum*i%p)%p;
	}
	cout<<ans<<endl;
	return 0;
}
