#include<bits/stdc++.h>
using namespace std;

const int maxN=100;
vector<int> adj[100];

void solve()
{
	int n,m;
	cin>>n>>m;
	int arr[n];
	
	vector<pair<int,int> > v;
	for(int i=1;i<n;i++)
	{
		cin>>arr[i];
		arr[i]*=-1;
		v.push_back({arr[i],i});
	}
	sort(arr+1,arr+n);
	
	long long val[n];
	memset(val,LONG_MAX,sizeof(val));
	
	val[0]=0;
	
	int t=1;
	val[v[0].second]=1;
	
	for(int i=1;i<v.size();i++)
	{
		int ii=v[i].second;
		/*
		long long mi=LONG_MAX;
		int ind=-1;
		for(int j=0;j<adj[ii].size();j++)
		{
			if(val[adj[ii][j]]<mi)
			{
				mi=val[adj[ii][j]];
				ind=j;
			}
		}
		*/
		if(v[i].second==v[i-1].second)
		{
			val[ii]=val[v[i-1].second];
		}
		else
		{
			t=v[i-1].second+1;
			val[ii]=t;
		}
	}
	int u,v1;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v1,u--,v1--;
		adj[u].push_back(v1);
		adj[v1].push_back(u);
		
		if(val[u]>val[v1])
		{
			swap(u,v1);
		}
		cout<<max((long long)0,val[v1]-val[u])<<' ';
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
