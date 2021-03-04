#include<bits/stdc++.h>
using namespace std;

const int maxN=2000;
vector<int> adj[maxN];

int dfs(int i,int p)
{
	int level=1;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
			level=max(level,dfs(ch,i)+1);
	}
	return level;
}
int main()
{
	int n;
	cin>>n;
	
	int p[n];
	vector<int> root;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		
		if(p[i]!=-1)
		{
			p[i]--;
			adj[p[i]].push_back(i);
		}
		else
		{
			root.push_back(i);
		}
	}
	
	int ma=0;
	for(auto ele:root)
	{
		ma=max(ma,dfs(ele,-1));
	}
	
	cout<<ma<<endl;
	return 0;
}
