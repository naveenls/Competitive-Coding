#include <bits/stdc++.h> 
using namespace std; 
  
const int maxN=1e5+1;

vector<int> adj[maxN];

int bfsWithDistance(bool mark[], int u,  vector<int>& dis) 
{ 
    int lastMarked; 
    queue<int> q; 
  
    q.push(u); 
    dis[u] = 0; 
  
    while (!q.empty()) 
    { 
        u = q.front();      q.pop(); 
        if (mark[u]) 
            lastMarked = u; 

        for (int i = 0; i < adj[u].size(); i++) 
        { 
            int v = adj[u][i]; 
              
            if (dis[v] == -1) 
            { 
                dis[v] = dis[u] + 1; 
                q.push(v); 
            } 
        } 
    } 
    return lastMarked;
} 

int nodesKDistanceFromMarked(int V, int marked[], int N, int K) 
{ 

    bool mark[V] = {false}; 
    for (int i = 0; i < N; i++) 
        mark[marked[i]] = true;
  
    vector<int> tmp(V, -1), dl(V, -1), dr(V, -1); 

    int u = bfsWithDistance( mark, 0, tmp); 

    int v = bfsWithDistance( mark, u, dl); 

    bfsWithDistance( mark, v, dr); 
  
    int res = 0; 
    for (int i = 0; i < V; i++) 
    { 
        if (dl[i] <= K && dr[i] <= K) 
            res++; 
    } 
    return res; 
} 
  
int main() 
{ 
    int V,N,K;
    cin>>V>>N>>K;
    
    int marked[N];
    for(int i=0;i<N;i++)
    {
    	cin>>marked[i];
    	marked[i]--;
	}
	int a,b;
	for(int i=0;i<V-1;i++)
	{
		cin>>a>>b,a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
    cout << nodesKDistanceFromMarked( V, marked, N, K); 
    return 0; 
} 
