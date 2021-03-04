#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5;

vector<int> adj[maxN];
set<pair<int,int> > s;

int count_=0;
int n;

void dfs(int i,int p)
{
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			if(s.find({i,ch})!=s.end())
				count_++;
				
			dfs(ch,i);
		}
	}
}

int ans[maxN];

void dfs1(int i,int p,int num,int d)
{	
	ans[i]=n-1-d-count_ + 2*num;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			if(s.find({i,ch})!=s.end())
				dfs1(ch,i,num+1,d+1);
			else
				dfs1(ch,i,num,d+1);
		}
	}
}
int main()
{
	cin>>n;
	
	int u,v;
	
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--,v--;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
		
		s.insert({u,v});
	}
	
	dfs(0,-1);
	dfs1(0,-1,0,0);
	
	int mi=n;
	for(int i=0;i<n;i++)
	{
		mi=min(mi,ans[i]);
	}
	
	cout<<mi<<endl;
	for(int i=0;i<n;i++)
	{
		if(ans[i]==mi)
			cout<<i+1<<' ';
	}
	return 0;
}
