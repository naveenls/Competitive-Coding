#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+1;

vector<pair<int,pair<int,int> > > edges;
vector<int> adj[maxN];

bool visited[maxN];
int disc[maxN];
int low[maxN]; 
int parent[maxN];

set<pair<int,int> > bridges;

bool compare(int i,int j)
{
	return edges[i]<edges[j];
}

int TIME=0;
void bridgeUtil(int u) 
{ 
  
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

void bridge(set<int> &root) 
{
	TIME=0;
    for (auto ele:root) 
    { 
    	//cout<<ele<<' ';
        parent[ele] = -1; 
        visited[ele] = false; 
    }
 	//cout<<endl;
    for (auto ele:root) 
        if (visited[ele] == false)
            bridgeUtil(ele); 
} 

int find_par(int a,int par[])
{
	if(a==par[a])
		return a;
	
	par[a]=find_par(par[a],par);
	return par[a];
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	int a,b,w;
	
	vector<int> v;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		a--,b--;
		
		v.push_back(i);
		edges.push_back({w,{a,b}});	
	}
	
	sort(v.begin(),v.end(),compare);
	
	int par[n],size[n];
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		size[i]=1;
	}
	
	int ans[m];
	memset(ans,-1,sizeof(ans));
	
	for(int i=0;i<m;)
	{		
		int j=i+1;
		while(j<m && edges[v[j]].first==edges[v[i]].first)
		{
			j++;
		}
		
		map<pair<int,int> ,vector<int> > mp;
		
		set<int> root;
		set<pair<int,int> > edge;
		
		int cnt=0;
		for(int t=i;t<j;t++)
		{
			int u_=edges[v[t]].second.first;
			int v_=edges[v[t]].second.second;
			
			int a=find_par(u_,par);
			int b=find_par(v_,par);
			
			if(a==b)
			{
				ans[t]=2;
			}
			else
			{
				root.insert(a);
				root.insert(b);
				
				mp[{min(a,b),max(a,b)}].push_back(t);

				edge.insert({min(a,b),max(a,b)});
			}
		}
		for(auto ele:root)
		{
			adj[ele].clear();
		}
		
		for(auto ele:edge)
		{
			//cout<<ele.first<<' '<<ele.second<<endl;
			adj[ele.first].push_back(ele.second);
			adj[ele.second].push_back(ele.first);
		}
		bridges.clear();

		bridge(root);
		//cout<<bridges.size()<<endl;
		for(auto bridge:bridges)
		{
			//cout<<bridge.first<<' '<<bridge.second<<endl;
			if(mp[bridge].size()==1)
			{
				for(auto ind:mp[bridge])
				{
					ans[ind]=0;
				}	
			}
		}

		for(int t=i;t<j;t++)
		{
			int u_=edges[v[t]].second.first;
			int v_=edges[v[t]].second.second;
			
			int a=find_par(u_,par);
			int b=find_par(v_,par);
			
			if(a!=b)
			{
				if(size[a]>size[b])
				{
					size[b]+=size[a];
					par[a]=b;	
				}
				else
				{
					size[a]+=size[b];
					par[b]=a;
				}
			}
		}
		
		i=j;
	}
	
	int new_ans[m];
	for(int i=0;i<m;i++)
	{
		new_ans[v[i]]=ans[i];
	}
	string ans_="";
	for(int i=0;i<m;i++)
	{
		if(new_ans[i]==-1)
		{
			ans_+="at least one\n";
		}
		else if(new_ans[i]==0)
		{
			ans_+="any\n";
		}
		else
		{
			ans_+="none\n";
		}
	}
	cout<<ans_<<endl;
}
