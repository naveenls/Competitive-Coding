#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
const int maxN=1e5+1;

long long DP[maxN+1];
int main()
{
	int t,k;
	cin>>t>>k;

	for(int i=0;i<k;i++)
	{
		DP[i]=1;
	}
	for(int i=k;i<maxN;i++)
	{
		DP[i]=(DP[i-1]+DP[i-k])%mod;
	}
	for(int i=1;i<maxN;i++)
	{
		DP[i]=(DP[i]+DP[i-1])%mod;
	}
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<(DP[b]-DP[a-1]+mod)%mod<<endl;
	}
	return 0;
}
