#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+9;

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
	
	long long temp=n/k;
	long long rem=n-temp*k;
	long long ans=temp*(k-1)+rem;
	if(ans>m)
	{
		cout<<m;
		return 0;
	}
	m-=ans;
	long long t1=(power(2,m+1)-2+4*mod)%mod;
	t1=(k*(t1))%mod;
	t1=(t1-((k-1)*m)%mod+mod)%mod;
	ans=(ans+t1)%mod;
	cout<<ans<<endl;
	return 0;
}
