#include<bits/stdc++.h>
using namespace std;
long long m=1000000007;


int main()
{
	int n,k;
	cin>>n>>k;
	
	long long dp[k+1][n+1];
	for(int i=1;i<=n;i++)
	{
		dp[k][i]=1;
	}
		
	for(int p=k-1;p>=1;p--)
	{
		for(int i=1;i<=n;i++)
		{
			dp[p][i]=0;
			int j=i;
			while(j<=n)
			{
				if(j%i==0)
					dp[p][i]=(dp[p][i]+dp[p+1][j])%m;
				j++;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+dp[1][i])%m;
	}
	cout<<ans<<endl;
	return 0;
}
