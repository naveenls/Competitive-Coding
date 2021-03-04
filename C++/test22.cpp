#include<bits/stdc++.h>

using namespace std;
int n1,n2,k1,k2;

long long m= 100000000 ;

int dp[101][101][11][11];

int find(int n1,int n2,int i,int j)
{
	
	if(n1+n2==0)
	{
		return 1;
	}
	if(dp[n1][n2][i][j]!=-1)
		return dp[n1][n2][i][j];
		
	int ans=0;
	if(n1 && i)
		ans=(ans+find(n1-1,n2,i-1,k2))%m;
		
	if(n2 && j)
		ans=(ans+find(n1,n2-1,k1,j-1))%m;
		
	dp[n1][n2][i][j]=ans;	
	return ans;
}
int main()
{
	cin>>n1>>n2>>k1>>k2;
	memset(dp,-1,sizeof(dp));
	cout<<find(n1,n2,k1,k2);
}
