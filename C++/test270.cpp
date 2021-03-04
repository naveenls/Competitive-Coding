#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
} 
int main()
{
	long long n,m,k;
	cin>>n>>m>>k;
	
	if(k>n)
	{
		cout<<power(m,n)<<endl;
	}
	else if(k<n)
	{
		if(k==1)
		{
			cout<<power(m,n)<<endl;
		}
		else if(k%2)
		{
			cout<<m*m<<endl;
		}
		else
		{
			cout<<m<<endl;
		}
	}
	else
	{
		long long num=n-n/2;
		cout<<power(m,num)<<endl;
	}	
	return 0;
}
