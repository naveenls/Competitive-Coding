#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		
		cin>>n>>m;
		
		long long val[n][m];
		long long disc[n][m];
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>val[i][j];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>disc[i][j];
		}
		
		long long DP[n][m];
		
		long long mi_prev=1e18;
		
		for(int i=0;i<m;i++)
		{
			DP[0][i]=val[0][i];
			mi_prev=min(mi_prev,DP[0][i]);	
		}
			
		for(int i=1;i<n;i++)
		{
			long long mi_pre=1e18;
			
			for(int j=0;j<m;j++)
			{
				DP[i][j]=min(DP[i-1][j] + max(0LL,val[i][j]-disc[i-1][j]),mi_prev+val[i][j]);
				mi_pre=min(mi_pre,DP[i][j]);
			}
			
			mi_prev=mi_pre;
		}
		cout<<mi_prev<<endl;
	}
	return 0;
}
