#include<bits/stdc++.h>

using namespace std;

const int maxN=48;
vector<int> adj[maxN];
bool col[maxN]={0};
int n;

void dfs(int i,vector<int> &v)
{
	if(!col[i])
	{
		col[i]=1;
		v.push_back(i);
		for(int j=0;j<adj[i].size();j++)
		{
			dfs(adj[i][j],v);
		}
	}
}
int main()
{
	int m;
	cin>>n>>m;
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v,u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector< vector<int> > three;
	vector< vector<int> > two;
	vector<int> one;
	
	for(int i=0;i<n;i++)
	{
		if(!col[i])
		{
			vector<int> v;
			dfs(i,v);
			if(v.size()>3)
			{
				cout<<-1;
				return 0;
			}
			if(v.size()==3)
			{
				three.push_back(v);
			}
			if(v.size()==2)
			{
				two.push_back(v);
			}
			if(v.size()==1)
			{
				one.push_back(v[0]);
			}			
		}
	}
	if(two.size()>one.size())
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<three.size();i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<three[i][j]+1<<' ';
		}
		cout<<endl;
	}
	for(int i=0;i<two.size();i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<two[i][j]+1<<' ';
		}
		cout<<one[i]+1<<' ';
		cout<<endl;
	}
	for(int i=two.size();i<one.size();i+=3)
	{
		cout<<one[i]+1<<' '<<one[i+1]+1<<' '<<one[i+2]+1<<endl;
	}
	return 0;
}
