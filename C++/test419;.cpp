#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5+1;
vector<int> adj[maxN];

int n;

long long ans=0;

void calc_val(int a,int b)
{
	//cout<<a<<' '<<b<<endl;
	if(a<b)
	{
		ans+=(long long)(b-a)*(n-b+1);	
	}
	else
	{
		ans+=(long long)(a-b)*b;
	}	
}

void dfs(int i,int p)
{
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			calc_val(i,ch);
			dfs(ch,i);
		}
	}
}
int main()
{
	cin>>n;
	
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ans+=n;
	
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
