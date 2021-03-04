#include<bits/stdc++.h>
using namespace std;

long long find_max(long long a)
{
	for(long long i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			return a/i;
		}
	}
	
	return a;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long n;
		cin>>n;

		long long temp=find_max(n);
		
		if(temp==n)
		{
			cout<<1<<' '<<n-1<<endl;
			continue;
		}
		
		long long a1=n/temp;
		long long a2=a1-1;
		a1=1;
		
		cout<<temp*a1<<' '<<temp*a2<<endl;
	}
	return 0;
}
