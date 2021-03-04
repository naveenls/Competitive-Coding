#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

vector<int> adj[maxN];
bool col[maxN]={0};
int depth[maxN];
int par[maxN];

int n,m,k;

void dfs(int i)
{
	col[i]=1;
	
	for(auto ch:adj[i])
	{
		if(!col[ch])
		{
			depth[ch]=depth[i]+1;
			par[ch]=i;
			
			dfs(ch);
		}
		else
		{
			if(depth[i]-depth[ch]+1>=k+1)
			{
				cout<<depth[i]-depth[ch]+1<<endl;
				
				int temp=i;
				
				while(temp!=ch)
				{
					cout<<temp+1<<' ';
					temp=par[temp];
				}
				cout<<ch+1<<endl;
				
				exit(0);
			}
		}
	}
}
int main()
{
	cin>>n>>m>>k;
	
	int u,v;
	
	for(int i=0;i<m;i++)
	{
		cin>>u>>v,u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	depth[0]=0;
	par[0]=-1;
	dfs(0);
	return 0;
}
