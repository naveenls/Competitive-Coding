#include<bits/stdc++.h>
using namespace std;

long long m=1e9+7;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

const int maxN=2*1e5;
set<int> adj[maxN];

bool visited[maxN];
int disc[maxN];
int low[maxN]; 
int parent[maxN];

set<pair<int,int> > bridges;

int sz=0;
bool col[maxN];

void dfs(int i)
{
	if(!col[i])
	{
		sz++;
		col[i]=1;
		for(auto ch:adj[i])
			dfs(ch);
	}	
}
void bridgeUtil(int u) 
{ 
    static int TIME=0;
    visited[u] = true; 
  
    disc[u] = low[u] = ++TIME; 
  
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
    {
        int v = *i;  
  
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(v); 

            low[u]  = min(low[u], low[v]); 

            if (low[v] > disc[u]) 
              bridges.insert({min(u,v),max(u,v)});
        } 
  
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 

void bridge(int n) 
{
    for (int i=0;i<n;i++) 
    { 
        parent[i] = -1; 
        visited[i] = false; 
    }
 	
    for (int i=0;i<n;i++) 
        if (visited[i] == false)
            bridgeUtil(i); 
} 

int main()
{
	int n;
	cin>>n;
	
	int a;
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		a--;
		adj[i].insert(a);
		adj[a].insert(i);	
	}		
	bridge(n);
	
	long long ans=1;
	for(auto ele:bridges)
	{
		adj[ele.first].erase(ele.second);
		adj[ele.second].erase(ele.first);
		
		ans=(ans*2)%m;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!col[i])
		{
			sz=0;
			dfs(i);
			
			if(sz>1)
				ans=(ans*((power(2,sz)-2+m))%m)%m;
		}
	}
	cout<<ans<<endl;
	return 0;
}
