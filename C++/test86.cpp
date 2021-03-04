#include<bits/stdc++.h>
using namespace std;
const int maxN=1000;

vector< pair<int,int>> adj[maxN][maxN];
string arr[maxN];
int DP[maxN][maxN];
int col[maxN][maxN];
bool has_cycle=0;

void dfs(int i,int j)
{
		
	if(DP[i][j]!=-1)
		return;
		
	DP[i][j]=1;
	col[i][j]=1;
	
	for(auto ch:adj[i][j])
	{
		if(col[ch.first][ch.second]==0)
		{
			dfs(ch.first,ch.second);
		}
		else if(col[ch.first][ch.second]==1)
		{
			has_cycle=1;
			return;
		}

		if(has_cycle)
			return;
			
		DP[i][j]=max(DP[i][j],DP[ch.first][ch.second]+1);
	}
	col[i][j]=2;
}
int main()
{
 	int n,m;
 	cin>>n>>m;
 	
 	for(int i=0;i<n;i++)
 	{
 		cin>>arr[i];
	}
	memset(DP,-1,sizeof(DP));
	memset(col,0,sizeof(col));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='D')
			{
				if(i+1<n && arr[i+1][j]=='I')
				{
					adj[i][j].push_back({i+1,j});
				}
				if(i-1>=0 && arr[i-1][j]=='I')
				{
					adj[i][j].push_back({i-1,j});
				}
				if(j-1>=0 && arr[i][j-1]=='I')
				{
					adj[i][j].push_back({i,j-1});
				}
				if(j+1<m && arr[i][j+1]=='I')
				{
					adj[i][j].push_back({i,j+1});
				}
			}
			else if(arr[i][j]=='I')
			{
				if(i+1<n && arr[i+1][j]=='M')
				{
					adj[i][j].push_back({i+1,j});
				}
				if(i-1>=0 && arr[i-1][j]=='M')
				{
					adj[i][j].push_back({i-1,j});
				}
				if(j-1>=0 && arr[i][j-1]=='M')
				{
					adj[i][j].push_back({i,j-1});
				}
				if(j+1<m && arr[i][j+1]=='M')
				{
					adj[i][j].push_back({i,j+1});
				}
			}
			else if(arr[i][j]=='M')
			{
				if(i+1<n && arr[i+1][j]=='A')
				{
					adj[i][j].push_back({i+1,j});
				}
				if(i-1>=0 && arr[i-1][j]=='A')
				{
					adj[i][j].push_back({i-1,j});
				}
				if(j-1>=0 && arr[i][j-1]=='A')
				{
					adj[i][j].push_back({i,j-1});
				}
				if(j+1<m && arr[i][j+1]=='A')
				{
					adj[i][j].push_back({i,j+1});
				}
			}
			else
			{
				if(i+1<n && arr[i+1][j]=='D')
				{
					adj[i][j].push_back({i+1,j});
				}
				if(i-1>=0 && arr[i-1][j]=='D')
				{
					adj[i][j].push_back({i-1,j});
				}
				if(j-1>=0 && arr[i][j-1]=='D')
				{
					adj[i][j].push_back({i,j-1});
				}
				if(j+1<m && arr[i][j+1]=='D')
				{
					adj[i][j].push_back({i,j+1});
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!col[i][j])
				dfs(i,j);
				
			if(has_cycle)
			{
				cout<<"Poor Inna!";
				return 0;
			}
		}
	}
	int ma=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='D')
			{
				ma=max(ma,DP[i][j]/4);
			}
		}
	}
	if(ma==0)
	{
		cout<<"Poor Dima!";
	}
	else
		cout<<ma;
    return 0;
}
