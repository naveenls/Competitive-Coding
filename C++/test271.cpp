#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

vector<pair<int,long long> > adj[maxN];

int parent[maxN];
long long sum[maxN];

vector<int> leaf;

void dfs(int i,int p,long long s)
{
	int num=0;
	parent[i]=p;
	sum[i]=s;
	
	for(auto ch:adj[i])
	{
		if(ch.first!=p)
			dfs(ch.first,i,s+ch.second),num++;
	}
	if(!num)
		leaf.push_back(i);
}
int main()
{
	int n;
	cin>>n;
	
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	
	int u,v;
	long long w;
	
	long long ss=0;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v>>w;
		u--,v--;
		ss+=w;
		
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});	
	}	
	
	dfs(0,-1,0);
	
	long long mx=0;
	for(auto i:leaf)
	{
		mx=max(mx,sum[i]);
	}
	cout<<2*ss-mx<<endl;
	return 0;
}

