#include<bits/stdc++.h>
using namespace std;
const int maxN=2*1e5;

vector<int> adj[maxN];
vector<int> adjR[maxN];

int col[maxN];
int min1[maxN];
int min2[maxN];

bool back_edge;
int n,m;

void dfs(int i)
{
	col[i]=1;
	for(auto ch:adj[i])
	{
		if(col[ch]==0)
		{
			dfs(ch);
		}
		else if(col[ch]==1)
		{
			back_edge=1;
			break;
		}
		min1[i]=min(min1[i],ch);
	}
	col[i]=2;
}

void dfs1(int i)
{
	col[i]=1;
	for(auto ch:adjR[i])
	{
		if(col[ch]==0)
		{
			dfs1(ch);
		}

		min2[i]=min(min2[i],ch);
	}
	col[i]=2;
}
int main()
{
	cin>>n>>m;
	int u,v;
	memset(col,0,sizeof(col));
	back_edge=0;
	for(int i=0;i<n;i++)
	{
		min1[i]=min2[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		cin>>u>>v,u--,v--;

		adj[u].push_back(v);
		adjR[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
	    if(col[i]==0)
	        dfs(i);
	}
	if(back_edge)
	{
		cout<<-1;
		return 0;
	}
	memset(col,0,sizeof(col));
	for(int i=0;i<n;i++)
	{
	    if(col[i]==0)
	        dfs1(i);
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(min(min1[i],min2[i])>=i)
		{
			cnt++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(min(min1[i],min2[i])>=i)
		{
			cout<<"A";
		}
		else
			cout<<"E";
	}
	return 0;
}
