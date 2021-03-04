#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;
set<int> adj[maxN];
int vis[maxN]={0};

set<int> s;

void dfs(int i)
{
	vis[i]=1;
	vector<int> v;
	
	for(auto ele:s)
	{
		if(adj[i].find(ele)==adj[i].end())
		{
			v.push_back(ele);	
		}
	}
	
	for(auto j:v)
	{
		s.erase(j);
	}
	
	for(auto j:v)
		dfs(j);
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v,u--,v--;
		
		adj[u].insert(v);
		adj[v].insert(u);
	}
	
	for(int i=0;i<n;i++)
	{
		s.insert(i);
	}
	
	int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			cnt++;
			dfs(i);
		}
	}
	
	cout<<cnt-1<<endl;
	return 0;
	
}
