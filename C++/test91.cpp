#include<bits/stdc++.h>
using namespace std;

long long factorize(long long n)
{
	if(n%2==0)
	{
		return 2;
	}
	for(long long i=3;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			return i;
		}
	}
	return n;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k;
		cin>>n>>k;
		long long fac=factorize(n);
		
		if(fac==2)
		{
			cout<<n+2*k<<endl;
		}
		else
		{
			cout<<n+fac+2*(k-1)<<endl;
		}

	}
}
