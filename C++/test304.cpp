#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5;
vector<int> adj[maxN];
long long arr[maxN];

long long val[maxN];
long long max_val[maxN];

long long ans=-1e18;

void dfs(int i,int p)
{
	val[i]=arr[i];
	max_val[i]=-1e18;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			dfs(ch,i);
			val[i]+=val[ch];
			max_val[i]=max(max_val[i],max_val[ch]);
		}
	}
	max_val[i]=max(max_val[i],val[i]);
}

multiset<long long> m_set;

void dfs1(int i,int p)
{
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			m_set.insert(max_val[ch]);
		}
	}
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			m_set.erase(m_set.find(max_val[ch]));
			dfs1(ch,i);
			m_set.insert(max_val[ch]);
		}
	}
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			m_set.erase(m_set.find(max_val[ch]));
		}
	}
	
	if(m_set.size())
		ans=max(ans,max_val[i]+*m_set.rbegin());
}
int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v,u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0,-1);
	dfs1(0,-1);
	if(ans==-1e18)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
	return 0;
}
