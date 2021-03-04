#include<bits/stdc++.h>
using namespace std;

const int maxN=200;
set<int> adj[maxN];

pair<int, int> bfs(int u) 
{ 
    int dis[maxN]; 
    memset(dis, -1, sizeof(dis)); 
  
    queue<int> q; 
    q.push(u); 
  
    dis[u] = 0; 
  
    while (!q.empty()) 
    { 
        int t = q.front();       q.pop(); 
  
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it; 

            if (dis[v] == -1) 
            { 
                q.push(v); 
 
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
  
    int maxDis = 0; 
    int nodeIdx; 
  
    for (int i = 0; i < maxN; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 
    return make_pair(nodeIdx, maxDis); 
} 
  
int longestPathLength(int a) 
{ 
    pair<int, int> t1, t2; 

    t1 = bfs(a); 
  
    t2 = bfs(t1.first); 
  
    return t2.second; 
} 
int main()
{
	int n;
	cin>>n;
	
	int a,b;
	vector<pair<int,int> > edges;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b,a--,b--;
		edges.push_back({a,b});
		
		adj[a].insert(b);
		adj[b].insert(a);
	}
	int ma=0;
	for(auto ele:edges)
	{
		int a=ele.first;
		int b=ele.second;
		
		adj[a].erase(b);
		adj[b].erase(a);
		
		int l1=longestPathLength(a);
		int l2=longestPathLength(b);
		
		ma=max(ma,l1*l2);
				
		adj[a].insert(b);
		adj[b].insert(a);
	}
	cout<<ma<<endl;
	return 0;
}
