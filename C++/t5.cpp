#include<bits/stdc++.h>

using namespace std;

long long p=998244353;

const int maxN=5*1e5+10;
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

int main()
{
	long long n,k;
	cin>>n>>k;
	nCrModPFermat(n);
	long long arr[n+1]={0};
	
	long long ans=0;
	
	for(int i=1;i<n+1;i++)
	{
		int j=i;
		while(j<n+1)
		{
			arr[i]++;
			j+=i;
		}
		if(arr[i]>=k)
		{
			ans=(ans+nCr(arr[i]-1,k-1))%p;
		}
	}
	cout<<ans<<endl;
	return 0;
}
