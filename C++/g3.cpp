#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5;

int par[MAXN][17]; // initially all -1
vector<int> adj[maxN];

void dfs(int v,int p = -1){
	par[v][0] = p;
	if(p + 1)
		h[v] = h[p] + 1;
		
	for(int i = 1;i < MAXLOG;i ++)
		if(par[v][i-1] + 1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : adj[v])	if(p - u)
		dfs(u,v);
}


int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] + 1 and h[par[v][i]] >= h[u])
			v = par[v][i];

	if(v == u)
		return v;
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] - par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N,Q;
		cin>>N>>Q;
		int arr[N];
		
		int u,v;
		for(int i=0;i<N-1;i++)
		{
			
		}
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];	
		}	
	}
	
	return 0;
}
