#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int p,int d,vector<vector<int> > &adj,int par[],int depth[])
{
	if(depth[i]==-1)
	{
		depth[i]=d;
		par[i]=p;
		
		for(auto j:adj[i])
		{
			dfs(j,i,d+1,adj,par,depth);
		}
	}
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
		
		vector<vector<int> > adj(n);
		
		int u,v;
		
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			u--,v--;
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		int par[n];
		int depth[n];
		
		memset(depth,-1,sizeof(depth));
		
		dfs(0,-1,1,adj,par,depth);
		
		int val=n-n/2;
		
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			if(depth[i]>=val)
			{
				cout<<"PATH"<<endl;
				cout<<depth[i]<<endl;
				
				while(i!=-1)
				{
					cout<<i+1<<' ';
					i=par[i];
				}
				cout<<endl;
				
				flag=1;
				break;
			}
		}
		
		if(!flag)
		{	
			vector<pair<int,int> > v;
			
			map<int,vector<int> > mp;
			
			for(int i=0;i<n;i++)
			{
				mp[depth[i]].push_back(i);	
			}
			
			for(auto ele:mp)
			{
				for(int i=0;i+1<ele.second.size();i+=2)
				{
					v.push_back({ele.second[i]+1,ele.second[i+1]+1});			
				}
			}
			
			cout<<"PAIRING"<<endl;
			cout<<v.size()<<endl;
			for(auto ele:v)
			{
				cout<<ele.first<<' '<<ele.second<<endl;
			}
		}
	}
	return 0;
}
