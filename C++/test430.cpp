#include<bits/stdc++.h>
using namespace std;

map<long long,int> mp;

void factorize(long long a)
{
	int cnt=0;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			cnt=0;
			
			while(a%i==0)
			{
				a/=i;
				cnt++;
			}
			
			mp[i]=cnt;
		}
	}
	
	if(a>1)
	{
		mp[a]=1;
	}
}

long long mod=1e9+7;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
} 

long long modInverse(long long a) 
{ 
    return power(a, mod-2);
} 

const int maxK=1e4+1;
long long DP[52][maxK];

int main()
{
	long long n;
	int k;
	cin>>n>>k;
	
	factorize(n);
	
	long long ans=1;
	
	for(auto fac:mp)
	{
		for(int i=0;i<=fac.second;i++)
		{
			DP[i][0]=power(fac.first,i);
		}
		for(int i=1;i<=fac.second;i++)
		{
			DP[i][0]=(DP[i][0] + DP[i-1][0])%mod;
		}
		
		for(int t=1;t<=k;t++)
		{
			for(int i=0;i<=fac.second;i++)
			{
				DP[i][t]=modInverse(i+1)*DP[i][t-1]%mod;
			}
			for(int i=1;i<=fac.second;i++)
			{
				DP[i][t]=(DP[i][t] + DP[i-1][t])%mod;
			}
		}
		ans=(ans*(DP[fac.second][k]-DP[fac.second-1][k] + mod)%mod);
	}
	cout<<ans<<endl;
	return 0;
}
