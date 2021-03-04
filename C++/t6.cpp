#include<bits/stdc++.h>
using namespace std;

# define INF 1e18

const int maxN=1e5+10;

vector<pair<int,int> > adj[maxN];
map<int,int> nex[maxN];

int n,m;

void shortestPath(int src) 
{ 

    set< pair<long long, int> > setds; 

    vector<long long> dist(n, INF); 
  
    setds.insert(make_pair((long long)nex[src][0], src)); 
    dist[src] =(long long) nex[src][0]; 

    while (!setds.empty()) 
    { 
 
        pair<long long, int> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 

        int u = tmp.second; 
  
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            if (dist[v] > (long long) dist[u] + weight) 
            { 
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                dist[v] = (long long) dist[u] + weight;
				
				if(nex[v].find(dist[v])!=nex[v].end())
				{
					dist[v]=(long long) nex[v][dist[v]];
				}
				
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    if(dist[n-1]==INF)
    {
    	cout<<-1<<endl;
	}
	else
	{
		cout<<dist[n-1]<<endl;
	}
} 

int main()
{
	cin>>n>>m;
	int a,b,c;
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		a--,b--;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	
	for(int i=0;i<n-1;i++)
	{
		int k;
		cin>>k;
		
		int temp;
		for(int j=0;j<k;j++)
		{
			cin>>temp;
			nex[i].insert({temp,temp});
		}
		
		for(auto itr=nex[i].rbegin();itr!=nex[i].rend();itr++)
		{
			if(nex[i].find(itr->first+1)!=nex[i].end())
			{
				auto itr1=--itr;
				itr++;
				itr->second=itr1->second;
			}
			else
			{
				itr->second=itr->first+1;
			}
		}
	}
	shortestPath(0);
	return 0;
}
