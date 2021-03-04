#include<bits/stdc++.h>
using namespace std;

vector<int> adj[50];
int arr[50];

int DP[50][50][2001];

int dfs(int i,int p,int rem)
{
	if(rem<=arr[i])
		return abs(i-p);
		
	if(DP[i][p][rem]!=-1)
		return DP[i][p][rem];
		
	int mi=1e9;
	
	for(auto ch:adj[i])
	{
		mi=min(mi,dfs(ch,i,rem-arr[i]));
	}
	DP[i][p][rem]=abs(i-p)+mi;
	
	return DP[i][p][rem];
}
int main()
{
	int n,s,k;
	cin>>n>>s>>k;
	s--;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	string col;
	cin>>col;
	
	memset(DP,-1,sizeof(DP));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j]>arr[i] && col[j]!=col[i])
			{
				//cout<<j<<' ';
				adj[i].push_back(j);
			}
		}
		//cout<<endl;
	}
	
	int mi=1e9;
	for(int i=0;i<n;i++)
	{
		mi=min(mi,abs(i-s)+dfs(i,i,k));
	}
	
	if(mi>=1e9)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<mi<<endl;
	}
	
	
	return 0;
}
