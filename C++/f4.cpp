#include<bits/stdc++.h>
using namespace std;

const int maxN=5000;

vector<int> adj[maxN];
vector<int> adjR[maxN];
int col[maxN]={0};
int maxDeph[maxN]={0};

void dfs(int i)
{
	if(col[i]==0)
	{
		col[i]=1;
		maxDepth[i]=1;
		for(auto ch:adj[i])
		{
			dfs(ch);
			maxDepth[i]=max(maxDepth[i],maxDepth[ch]+1);
		}
	}

}
int main()
{
	int n,m;
	cin>>n>>m;
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	memset(arr,0,sizeof(arr));
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v,u--,v--;
		adj[u].push_back(v);
		adjR[v].push_back(u);
	}
	
	for(int i=0;i<n;i++)
	{
		if(col[i]==0)
		{
			dfs(i);
		}
	}
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		if(col[i]>3)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		cout<<"NO";
		return 0;
	}
	
	for(int i=0;i<n;i++)
	{
		for(auto ch: adj[ch])
		{
			if(abs(col[i]-col[ch]))
		}
	}
	return 0;
}
