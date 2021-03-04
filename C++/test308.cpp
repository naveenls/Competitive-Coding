#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, int> iPair; 

const int maxN=1000;
vector<pair<long long,int> > adj[maxN];
vector<int> adj_n[maxN];

long long t[maxN];
long long c[maxN];

void shortestPath(int src,int n) 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

    vector<long long> dist(n, 1e18); 
  
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 

    while (!pq.empty()) 
    { 

        int u = pq.top().second; 
        pq.pop(); 
  
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 

            int v = (*i).first; 
            long long weight = (*i).second; 
  
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 

    for(int i=0;i<n;i++)
    {
    	//cout<<dist[i]<<' ';
    	if(dist[i]<=t[src] && i!=src)
    	{
    		adj_n[src].push_back(i);
		}
	}
	//cout<<endl;
}

void shortestPath_n(int src,int n,int y) 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

    vector<long long> dist(n, 1e18); 
  
    pq.push(make_pair(0, src)); 
    dist[src] = 0;

    while (!pq.empty()) 
    { 

        int u = pq.top().second; 
        pq.pop(); 
  
        for (auto i = adj_n[u].begin(); i != adj_n[u].end(); ++i) 
        { 

            int v = *i; 
  
            if (dist[v] > dist[u] + c[u]) 
            { 
                dist[v] = dist[u] + c[u]; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 

    if(dist[y]==1e18)
    {
    	cout<<-1<<endl;
	}
	else
	{
		cout<<dist[y]<<endl;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	int x,y;
	cin>>x>>y,x--,y--;
	
	int u,v;
	long long w;
	
	for(int i=0;i<m;i++)
	{
		cin>>u>>v,u--,v--;
		cin>>w;
		
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>t[i]>>c[i];
	}
	
	for(int i=0;i<n;i++)
	{
		shortestPath(i,n);
	}
	/*
	cout<<"hi"<<endl;
	for(int i=0;i<n;i++)
	{
		for(auto ele:adj_n[i])
		{
			cout<<ele<<' ';
		}
		cout<<endl;
	}*/
	shortestPath_n(x,n,y);
	
	return 0;
}
