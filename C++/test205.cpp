#include<bits/stdc++.h>
using namespace std;

const int maxN=3*1e5;
vector<int> adj[maxN];
bool min_max[maxN];
int f[maxN];
int num_leaves[maxN];

void dfs(int i)
{
	num_leaves[i]=0;
	
	if(adj[i].size())
	{
		if(min_max[i]==0)
		{
			int sum=0;
			
			for(auto ch:adj[i])
			{
				dfs(ch);
				sum+=f[ch]-1;
				num_leaves[i]+=num_leaves[ch];
			}
			
			f[i]=sum+1;
		}
		else
		{
			int mi=1e9;
			
			for(auto ch:adj[i])
			{
				dfs(ch);
				num_leaves[i]+=num_leaves[ch];
				
				mi=min(mi,num_leaves[ch]-f[ch]);
			}
			f[i]=(num_leaves[i]-mi);
		}
	}
	else
	{
		f[i]=1;
		num_leaves[i]=1;
	}
}
int main()
{
	int n;
	cin>>n;	
	
	for(int i=0;i<n;i++)
	{
		cin>>min_max[i];
	}
	
	int a;
	for(int i=1;i<n;i++)
	{
		cin>>a;
		a--;
		adj[a].push_back(i);
	}
	
	dfs(0);
	cout<<f[0]<<endl;
	return 0;
}
