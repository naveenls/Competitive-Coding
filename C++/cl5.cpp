#include<bits/stdc++.h>
using namespace std;

long long mod=1e16;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		string arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		long long DP[n][m];
		int prev[n][m];
		
		DP[0][0]=arr[0][0]-'a';
		prev[0][0]=-2;
		
		for(int i=1;i<n;i++)
		{
			if(arr[i][0]=='#' || DP[i-1][0]==1e18)
			{
				DP[i][0]=1e18;
				continue;
			}

			prev[i][0]=1;
			DP[i][0]=(DP[i-1][0]*26+arr[i][0]-'a')%mod;
		}
		
		for(int j=1;j<m;j++)
		{
			if(arr[0][j]=='#' || DP[0][j-1]==1e18)
			{
				DP[0][j]=1e18;
				continue;
			}
			
			prev[0][j]=-1;
			DP[0][j]=(DP[0][j-1]*26+arr[0][j]-'a')%mod;
		}
		
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(arr[i][j]=='#')
				{
					DP[i][j]=1e18;
					continue;
				}
				
				if(DP[i-1][j]<DP[i][j-1])
				{
					prev[i][j]=1;
					DP[i][j]=(DP[i-1][j]*26 + arr[i][j]-'a')%mod;
				}
				else
				{
					prev[i][j]=-1;
					DP[i][j]=(DP[i][j-1]*26 + arr[i][j]-'a')%mod;
				}
			}
		}
		
		//cout<<DP[n-2][m-1]<<' '<<DP[n-1][m-2]<<endl;
		
		string ans="";
		
		int x=n-1,y=m-1;
		
		while(true)
		{
			ans.push_back(arr[x][y]);
			if(prev[x][y]==-1)
			{
				y--;
			}
			else if(prev[x][y]==1)
			{
				x--;
			}
			else
			{
				break;
			}
		}
		reverse(ans.begin(),ans.end());
		
		cout<<ans<<endl;
	}
	return 0;
}
