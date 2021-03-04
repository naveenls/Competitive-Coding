#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	long long arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	if(n>=m)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(arr[i]==0)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
		bool DP[n+1][m+1];
		memset(DP,0,sizeof(DP));
		DP[0][0]=true;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				int ind=((j-arr[i-1])%m +m)%m;
				
				DP[i][j]=DP[i-1][ind] || DP[i-1][j];
			}
		}
		
		if(DP[n][m])
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
