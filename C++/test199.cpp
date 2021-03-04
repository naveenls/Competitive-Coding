#include<bits/stdc++.h>
using namespace std;
const int maxN=2*1e5;

vector<int> adj[maxN];
int col[maxN]={0};

set<pair<int,int> > mp;
bool dfs(int i,int color)
{
	if(!col[i])
	{
		col[i]=color;
		
		bool has_odd=false;
		for(auto ch:adj[i])
		{
			has_odd=has_odd | dfs(ch,3-color);
		}
		return has_odd;
	}
	else if(col[i]==color)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	int u,v;
	vector<pair<int,int> > vec; 
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		u--,v--;
		
		vec.push_back({u,v});
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i=0;i<n;i++)
	{
		if(!col[i])
		{
			if(dfs(i,1))
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	string ans="";
	for(auto ele:vec)
	{
		if(col[ele.first]==1)
		{
			ans.push_back('0');
		}
		else
		{
			ans.push_back('1');
		}
	}
	cout<<ans<<endl;
	return 0;
}
