#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5;
vector<int> adj[maxN];

int par[maxN];
int level[maxN];
int in[maxN];
int out[maxN];

const int k=19;

int LCA[maxN][k];
int n;

static int tt=0;

void dfs(int i,int p,int l)
{
	in[i]=++tt;
	
	par[i]=p;
	level[i]=l;
	for(auto ch:adj[i])
	{
		if(ch!=p)
			dfs(ch,i,l+1);
	}
	
	out[i]=++tt;
}

void BuildTable()
{        
    for(int i=0;i<n;i++)
    {
    	for(int j=0;(1<<j)<n;j++)
    	{
    		LCA[i][j]=-1;
    	}
	}
	
	for(int i=0;i<n;i++)
	{
		LCA[i][0]=par[i];
	}
	
	for(int j=1;(1<<j)<n;j++)
	{
		for(int i=0; i<n;i++)
		{
			if(LCA[i][j-1]!=-1)
			{
				LCA[i][j]=LCA[LCA[i][j-1]][j-1];
			}
		}
	}
}

int get_lca(int p,int q)
{
	int temp;
	if(level[p]<level[q])
	{
		temp=p;
		p=q;
		q=temp;
	}
	int log;
	for(log=1;(1<<log)<=level[p];log++);
	log--;
	
	for(int i=log;i>=0;i--)
	{
		if(level[p]-(1<<i)>=level[q])
		{
			p=LCA[p][i];
		}
	}
	if(p==q)
		return p;
		
	for(int i=log;i>=0;i--)
	{
		if(LCA[p][i]!=-1 && LCA[p][i]!=LCA[q][i])
		{
			p=LCA[p][i];
			q=LCA[q][i];
		}
	}
	return par[p];
}

int main()
{
	int q;
	cin>>n;
	
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--,v--;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0,-1,0);
	BuildTable();
	
	cin>>q;
	
	int r;
	for(int i=0;i<q;i++)
	{
		cin>>r>>u>>v;
		r--,u--,v--;
		
		int a=get_lca(u,v);
		int b=get_lca(r,u);
		int c=get_lca(r,v);
		
		if(a==b && b==c)
		{
			cout<<a+1<<endl;
		}
		else if(a==b)
		{
			if(in[a]<=in[c] && out[a]>=out[c])
				cout<<c+1<<endl;
			else
				cout<<a+1<<endl;
		}
		else if(b==c)
		{
			if(in[a]<=in[b] && out[a]>=out[b])
				cout<<b+1<<endl;
			else
				cout<<a+1<<endl;
		}
		else
		{
			//cout<<in[b]<<' '<<in[c]<<' '<<out[b]<<' '<<out[c]<<endl;
			if(in[b]<=in[c] && out[b]>=out[c])
				cout<<c+1<<endl;
			else
				cout<<b+1<<endl;
		}
	}
	return 0;
}
