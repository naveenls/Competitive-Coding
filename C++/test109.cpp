#include<bits/stdc++.h>
using namespace std;

map<int,long long> mp;

long long p=1e9+7;

const int maxN=1e5;
long long fac[maxN+1]; 

long long power(long long x, long long y) 
{ 
    long long res = 1; 
  
    x = x % p;  
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
  
long long modInverse(long long n) 
{ 
    return power(n, p-2); 
} 

void nCrModPFermat(long long n) 
{    
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p;   
} 

long long nCr(long long n,long long r)
{
	if (r==0) 
      return 1; 
      
	return (fac[n]* modInverse(fac[r]) % p * 
            modInverse(fac[n-r]) % p) % p; 
}

void factorize(int a)
{
	int cnt=0;
	while(a%2==0)
	{
		a/=2;
		cnt++;
	}
	mp[2]+=cnt;
	
	for(int i=3;i*i<=a;++i)
	{
		if(a%i==0)
		{
			cnt=0;
			while(a%i==0)
			{
				a/=i;
				cnt++;
			}
			mp[i]+=cnt;
		}
	}
	if(a>1)
		mp[a]++;
}
int main()
{
	int n;
	cin>>n;
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		factorize(a);
	}
	long long ans=1;
	long long ma=0;
	for(auto itr=mp.begin();itr!=mp.end();++itr)
	{
		ma=max(ma,itr->second);
	}
	nCrModPFermat(ma+n+2);
	
	for(auto itr=mp.begin();itr!=mp.end();++itr)
	{
		ans=(ans*nCr(n+itr->second-1,n-1))%p;
	}
	cout<<ans<<endl;
	return 0;
}
