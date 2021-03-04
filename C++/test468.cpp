#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;
# define INF 0x3f3f3f3f 

vector<pair<int,int> > adj[maxN];
int par[maxN];

typedef pair<pair<int,int> , int> iPair;

void shortestPath(int src,int n) 
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    vector<pair<int,int> > dist(n, {INF,INF} ); 
  
    pq.push({{0,0}, src}); 
    dist[src] = {0,0}; 
  	par[src]=-1;
  	
    while (!pq.empty()) 
    { 

        auto u = pq.top().second; 
        pq.pop(); 
   
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        {
            int v = (*i).first; 
            int weight = 1-(*i).second; 
   
            if (dist[v].first > dist[u].first + 1) 
            { 
                dist[v].first = dist[u].first + 1;
				dist[v].second = dist[u].second + weight;

                pq.push(make_pair(dist[v], v)); 
                par[v]=u;
            }
            else if(dist[v].first==dist[u].first+1)
            {
            	if(dist[v].second>dist[u].second+weight)
            	{
            		dist[v].second = dist[u].second + weight;

                	pq.push(make_pair(dist[v], v)); 
                	par[v]=u;
				}
			}
        }
    }
} 

int main()
{
	int n,m;
	cin>>n>>m;
	
	int x,y,k;
	
	vector<pair<int,int> > edges;
	vector<int> type;
	
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>k;
		x--,y--;
		
		edges.push_back({x,y});
		type.push_back(k);
		
		adj[x].push_back({y,k});
		adj[y].push_back({x,k});
	}
	
	shortestPath(0,n);
	
	set<pair<int,int> > s;
	
	int start=n-1;
	while(par[start]!=-1)
	{
		s.insert({start,par[start]});
		start=par[start];
	}
	
	vector<pair<int,int> > ans;
	vector<int> ans_t;
	
	for(int i=0;i<edges.size();i++)
	{
		x=edges[i].first;
		y=edges[i].second;
		
		k=type[i];
		
		if(s.find({x,y})!=s.end() || s.find({y,x})!=s.end())
		{
			if(k==0)
			{
				ans.push_back({x,y});
				ans_t.push_back(1);
			}
		}
		else
		{
			if(k==1)
			{
				ans.push_back({x,y});
				ans_t.push_back(0);
			}
		}
	}
	
	cout<<ans.size()<<endl;
	
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first+1<<' '<<ans[i].second+1<<' '<<ans_t[i]<<endl;
	}
}
