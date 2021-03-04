#include<bits/stdc++.h>
using namespace std;

long long p=1e9+7;

const int maxN=110;

int arr[10];

long long DP[maxN][10];

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
    
    if(r>n)
    	return 0;
    	
	return (fac[n]* modInverse(fac[r]) % p * 
            modInverse(fac[n-r]) % p) % p; 
}

long long find_count(int len,int j)
{
	if(j==9 && arr[j]<=len)
		return 1;
	else if(j==9 && arr[j]>len)
		return 0;
	
	if(DP[len][j]!=-1)
	{
		return DP[len][j];
	}
	
	long long ans=0;
	
	if(j==0)
	{
		for(int i=arr[0];i<len;i++)
		{
			ans=(ans+nCr(len-1,i)*find_count(len-i,j+1)%p)%p;
		}	
	}
	else
	{
		for(int i=arr[j];i<=len;i++)
		{
			ans=(ans+nCr(len,i)*find_count(len-i,j+1)%p)%p;
		}
	}
	
	DP[len][j]=ans;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	memset(DP,-1,sizeof(DP));
	for(int i=0;i<10;i++)
	{
		cin>>arr[i];
	}
	
	nCrModPFermat(n+1);
	
	long long ans=0;
	
	for(int i=0;i<=n;i++)
	{
		ans=(ans+find_count(i,0))%p;
	}
	cout<<ans<<endl;
}
