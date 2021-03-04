#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > pairs;

int dfs(int i,int p,vector<int> &par,vector<int> &col,vector<set<int> > &adj)
{
	if(col[i]==0)
	{
		col[i]=1;
		par[i]=p;
		
		vector<int> odds;
		
		for(auto ch:adj[i])
		{
			int val=dfs(ch,i,par,col,adj);
			
			if(val!=-1)
				odds.push_back(val);
		}
		
		for(int j=0;j<odds.size();j++)
		{
			pairs.push_back({odds[j],i});
		}
		
		if(adj[i].size()%2)
		{
			if(odds.size()%2)
			{
				return -1;
			}
			else
			{
				return i;
			}
		}
		else
		{
			if(odds.size()%2)
			{
				return i;
			}
			else
			{
				return -1;
			}
		}
	}
	else
	{
		return -1;
	}
}

vector<int> find_cycle(int src,vector<set<int> > &adj) 
{
   	vector<int> temp; 
    temp.push_back(src);
    vector<int> result;
    
    while (temp.size()) 
	{
        int u = temp.back();
        if (adj[u].size())
		{
            int v = *adj[u].begin();
            temp.push_back(v); 
            adj[u].erase(adj[u].begin()); 
		    adj[v].erase(u);
        }
        else 
		{
            temp.pop_back();             
            result.push_back(u); 
        }
    }
    return result; 
}

vector<int> reduce(vector<int> temp)
{
	map<int,int> mp;
	
	int mi=1e9;
	int s,e;
	
	for(int i=0;i<temp.size();i++)
	{
		if(mp.find(temp[i])!=mp.end())
		{
			int diff=i-mp[temp[i]];
			
			if(diff%2 && diff<mi)
			{
				mi=diff;
				s=temp[i];
				e=i;
			}
		}
		mp[temp[i]]=i;
	}
	
	vector<int> new_vec;
	for(int i=0;i<s;i++)
	{
		new_vec.push_back(temp[i]);
	}
	for(int j=e;j<temp.size();j++)
	{
		new_vec.push_back(temp[j]);
	}
	
	return new_vec;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		vector<set<int> > adj(n);
		vector<pair<int,int> > edges;
		
		int u,v;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;	
			u--,v--;
			
			edges.push_back({min(u,v),max(u,v)});
			adj[u].insert(v);
			adj[v].insert(u);
		}
		
		vector<int> col(n,0);
		vector<int> par(n);
		
		pairs.clear();
		
		for(int i=0;i<n;i++)
		{
			if(col[i]==0)
			{
				dfs(i,-1,par,col,adj);
			}
		}
		
		for(auto pr:pairs)
		{
			int x=pr.first;
			int y=pr.second;
			
			while(x!=y)
			{
				adj[par[x]].erase(x);
				adj[x].erase(par[x]);
				
				x=par[x];
			}
		}
		
		set<pair<int,int> > red;
		set<pair<int,int> > green;
		
		for(int i=0;i<n;i++)
		{
			if(adj[i].size())
			{
				vector<int> temp=find_cycle(i,adj);
				
				if(temp.size()%2==0)
				{
					temp=reduce(temp);
				}
		
				bool flag=0;
				for(int j=0;j<temp.size()-1;j++)
				{
					if(flag)
					{
						red.insert({min(temp[j],temp[j+1]),max(temp[j],temp[j+1])});
					}
					else
					{
						green.insert({min(temp[j],temp[j+1]),max(temp[j],temp[j+1])});
					}
					flag=1-flag;
				}
			}
		}
		
		for(int i=0;i<m;i++)
		{
			if(red.count({edges[i].first,edges[i].second}))
			{
				cout<<1<<endl;
			}
			else if(green.count({edges[i].first,edges[i].second}))
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
