#include<bits/stdc++.h>
using namespace std;

long long p=1e9+7;

const int maxN=1e6;
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
	int n;
	cin>>n;
	
	nCrModPFermat(n);
	
	long long prod=1;
	for(int i=1;i<=n;i++)
	{
		prod=(prod*i)%p;
	}
	
	long long sum=0;
	
	for(int i=0;i<=n-1;i++)
	{
		sum=(sum+nCr(n-1,i))%p;
	}
	
	cout<<(prod-sum+p)%p;
	return 0;
}
