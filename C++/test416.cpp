#include<bits/stdc++.h>

using namespace std;

long long mod = 998244353;
const int maxK = 5003;

long long power(long long x, long long y, long long m) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}

long long modInverse(long long a, long long m) 
{ 
    return power(a, m-2, m);
} 

long long DP[maxK][maxK];

int main()
{
	long long n,m;
	int k;
	
	cin>>n>>m>>k;
	
	memset(DP,0,sizeof(DP));
	DP[0][0]=1;
	
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			DP[i+1][j]=(DP[i+1][j]+ DP[i][j]*j%mod)%mod;
			DP[i+1][j+1]=(DP[i+1][j+1] + DP[i][j]*(n-j)%mod)%mod;
		}
	}
	
	long long ans=0;
	for(int i=1;i<=k;i++)
	{
		ans=(ans+DP[k][i]*modInverse(power(m,i,mod),mod)%mod)%mod;
	}
	cout<<ans<<endl;
}

