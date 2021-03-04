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

long long cal(long long x,long long y){
    //cout<<x<<' '<<y<<endl;
	if(y==0)
		return 1;
	if(x == 0)
		return 1;
	if(x < 0)
		return 0;
		
	return nCr(x+y,x);
}

int main()
{
	long long ans = 0;
	nCrModPFermat(maxN);
	
	long long n,pp,c;
	cin>>n>>pp>>c;
	
	for(long long i=0;i<n;i++)
	{
	    long long diff;
	    
	    if(i<c)
	        diff = n - c*(pp-1) - pp - c;
	    else
	        diff = n - c*(pp-1) - pp - i;
	        
		ans = (ans + cal(diff,pp-1));
	}
	
	ans = (ans*(long long)(n-pp))%p;
	if(ans == 0)
	    ans = -1;
	    
	cout<<ans<<endl;
	
	return 0;
}
