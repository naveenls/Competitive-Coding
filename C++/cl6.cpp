#include<bits/stdc++.h> 
using namespace std;


int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	while (t --)
	{
		int n,m;
		
		cin>>n>>m;
		
		string arr[n];
		int val[n][m];
		string ans[n][m];
		
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]=='#')
				{
					val[i][j]=2;
				}
				else
				{
					val[i][j]=1;
				}
			}
		}
		
		int DP[n][m];
		
		DP[0][0] = val[0][0];
		ans[0][0].push_back(arr[0][0]);
		
		for (int i = 1; i < m; ++i)
		{
			DP[0][i] = val[0][i] + DP[0][i - 1];
			ans[0][i] = ans[0][i - 1];
			ans[0][i].push_back(arr[0][i]);
		}
		for (int i = 1; i < n; ++i)
		{
			DP[i][0] = val[i][0] + DP[i - 1][0];
			ans[i][0] = ans[i - 1][0];
			ans[i][0].push_back(arr[i][0]);
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < m; ++j)
			{
				if (DP[i - 1][j] < DP[i][j - 1])
				{
					DP[i][j] = DP[i - 1][j] + val[i][j];
					ans[i][j] = ans[i - 1][j];
					ans[i][j].push_back(arr[i][j]);
				}
				else if (DP[i - 1][j] > DP[i][j - 1])
				{
					DP[i][j] = DP[i][j - 1] + val[i][j];
					ans[i][j] = ans[i][j - 1];
					ans[i][j].push_back(arr[i][j]);
				}
				else
				{
					DP[i][j] = DP[i - 1][j] + val[i][j];
					if (ans[i - 1][j] < ans[i][j - 1])
					{
						ans[i][j] = ans[i - 1][j];
						ans[i][j].push_back(arr[i][j]);
					}
					else
					{
						ans[i][j] = ans[i][j - 1];
						ans[i][j].push_back(arr[i][j]);
					}
				}
			}
		}
		cout << ans[n - 1][m - 1] << '\n';
	
	}
	return 0;
}
