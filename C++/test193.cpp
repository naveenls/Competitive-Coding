#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

int col[maxN]={0};
bool colUD[maxN]={0};

vector<int> adj[maxN];
vector<int> adjUD[maxN];

int ans=0;

void dfs(int u,vector<int> &v)
{
	colUD[u]=1;
	v.push_back(u);
	
	for(auto ch:adjUD[u])
	{
		if(!colUD[ch])
			dfs(ch,v);
	}
}

bool dfs1(int u)
{
	col[u]=1;
	bool has_cycle=false;
	for(auto ch:adj[u])
	{
		if(!col[ch])
		{
			has_cycle=has_cycle | dfs1(ch);
		}
		else if(col[ch]==1)
		{
			return true;
		}
	}
	col[u]=2;
	return has_cycle;
}
void check_cycle(vector<int> &v)
{
	bool has_cycle=false;
	for(auto ele:v)
	{
		if(!col[ele])
		{
			has_cycle=has_cycle | dfs1(ele);
		}
	}
	ans+=v.size()-1;
	if(has_cycle)
		ans++;
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		
		adjUD[u].push_back(v);
		adjUD[v].push_back(u);
	}
	
	for(int i=0;i<n;i++)
	{
		if(!colUD[i])
		{
			vector<int> v;
			dfs(i,v);
			
			check_cycle(v);
		}
	}
	cout<<ans<<endl;
}
