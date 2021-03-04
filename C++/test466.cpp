#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

int main()
{
	int n,h;
	cin>>n>>h;
	
	long long DP[n+1][h+1];
	memset(DP,0,sizeof(DP));
	
	int arr[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
		
	if(arr[1]==h || arr[1]==h-1)
		DP[1][0]=1;
	
	if(arr[1]==h-1)
		DP[1][1]=1;
	
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=h;j++)
		{
			if(arr[i]+j==h)
			{
				if(j)
					DP[i][j]+=DP[i-1][j-1];
					
				DP[i][j]+=DP[i-1][j];
			}
			if(arr[i]+j==h-1)
			{
				DP[i][j]+=DP[i-1][j+1]*(j+1);
					
				DP[i][j]+=DP[i-1][j];
				DP[i][j]+=DP[i-1][j]*j;
			}
			DP[i][j]%=mod;
		}
	}
	
	cout<<DP[n][0];
	return 0;
}
