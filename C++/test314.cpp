#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e6+1;

long long DP[maxN];

long long mod= 1e9+7;

long long solve(int n)
{
	if(DP[n]!=-1)
		return DP[n];
		
	if(n%3==2)
	{
		DP[n]=(2*solve(n-2)%mod + solve(n-1))%mod;
	}
	else
	{
		DP[n]=(4+4*solve(n-4)%mod + 4*solve(n-3)%mod + solve(n-2))%mod;
	}
	return DP[n];
}
int main()
{
	memset(DP,-1,sizeof(DP));
	
	DP[0]=0;
	DP[1]=0;
	DP[2]=0;
	DP[3]=4;
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		cout<<solve(n)<<endl;
	}
	return 0;
}
