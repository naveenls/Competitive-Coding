#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5+10;
vector<int> adj[maxN];
long long arr[maxN];

long long sub_sum[maxN];
long long sub_cnt[maxN];
long long ans[maxN];

void dfs1(int i,int p)
{	
	for(auto ch:adj[i])
	{
		if(ch != p)
		{
			dfs1(ch,i);
			sub_sum[i] += sub_sum[ch];
			sub_cnt[i] += sub_cnt[ch];
		}
	}
	
	sub_sum[i] += sub_cnt[i];
	sub_cnt[i] += arr[i];
	
	//cout<<i<<' '<<sub_cnt[i]<<' '<<sub_sum[i]<<endl;
}

void dfs2(int i,int p, long long p_sum, long long p_cnt)
{
	ans[i] = p_sum + sub_sum[i] + p_cnt;
	
	for(auto ch:adj[i])
	{
		if(ch != p)
			dfs2(ch,i,p_sum+p_cnt+sub_sum[i]-sub_sum[ch]-sub_cnt[ch],p_cnt+sub_cnt[i]-sub_cnt[ch]);
	}
}	

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			
			sub_sum[i] = 0;
			sub_cnt[i] = 0;
			
			adj[i].clear();	
		}	
		
		int u,v;
		for(int i=0;i<n-1;i++)
		{
			cin>>u>>v;
			u--,v--;
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		dfs1(0,-1);
		dfs2(0,-1,0,0);
		
		for(int i=0;i<n;i++)
			cout<<ans[i]<<' ';
			
		cout<<endl;
	}
	return 0;
}
