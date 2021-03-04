#include<bits/stdc++.h>
using namespace std;

const int maxN=2000;
vector<pair<int,int> > adj[maxN];

int arr[maxN][maxN];
int val[maxN];

void dfs(int i,int p,int s)
{
	val[i]=s;
	
	for(auto ch:adj[i])
	{
		if(ch.first!=p)
			dfs(ch.first,i,s+ch.second);
	}
}

int find_parent(int i,int par[])
{
	if(i==par[i])
		return i;
		
	par[i]=find_parent(par[i],par);
	return par[i];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;	
	int par[n];
	
	vector<pair<int,pair<int,int> > > v;
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
			
			if(i!=j && !arr[i][j])
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			v.push_back({arr[i][j],{i,j}});
	}
	sort(v.begin(),v.end());
	
	for(auto ele:v)
	{
		auto pr=ele.second;
		
		int u=pr.first,v=pr.second;
		
		int a=find_parent(u,par),b=find_parent(v,par);
		//cout<<u<<' '<<v<<' '<<a<<' '<<b<<endl;
		if(a!=b)
		{
			adj[u].push_back({v,ele.first});
			adj[v].push_back({u,ele.first});
			
			par[a]=b;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		dfs(i,-1,0);
		
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]!=val[j])
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
