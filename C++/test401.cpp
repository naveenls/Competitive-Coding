#include<bits/stdc++.h>
using namespace std;

long long mod=998244353;

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

int main()
{
	int n;
	cin>>n;
	
	long long arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	long long DP[n+1][2];
	DP[0][0]=0;
	DP[0][1]=1;
	
	for(int i=1;i<=n;i++)
	{
		DP[i][0]=(DP[i-1][0]+DP[i-1][1])%mod*100%mod;
		DP[i][1]=(DP[i-1][1]*arr[i-1])%mod;
	}
	
	cout<<(DP[n][0]*modInverse(DP[n][1],mod))%mod<<endl;
	return 0;
}
