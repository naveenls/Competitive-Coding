#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

vector<int> adj[maxN];
int arr[maxN];

int cnt[501];
int minD[501];

int mini_dist;

vector<int> near[501];

void preproc()
{
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=500;j++)
		{
			int val=sqrt(i*j);
			
			if(val*val==i*j)
			{
				near[i].push_back(j);
			}
		}
	}
}

long long ans;

void reset(int n)
{
	for(int i=0;i<n;i++)
		adj[i].clear();
		
	memset(cnt,0,sizeof(cnt));
	ans=0;
	mini_dist=1e9;
	
	for(int j=1;j<=500;j++)
	{
		minD[j]=-1e9;
	}
}

void dfs(int i,int p,int d)
{
	for(auto j:near[arr[i]])
	{
		ans+=cnt[j];
		
		mini_dist=min(mini_dist,d-minD[j]);
	}
	
	cnt[arr[i]]++;
	
	int prev=minD[arr[i]];
	
	minD[arr[i]]=d;
	
	for(auto ch:adj[i])
	{
	    if(ch!=p)
		    dfs(ch,i,d+1);
	}
	
	cnt[arr[i]]--;
	minD[arr[i]]=prev;
}

int main()
{
	int t;
	cin>>t;
	preproc();
	
	while(t--)
	{
		int n;
		cin>>n;
		
		reset(n);
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		int u,v;
		
		for(int i=0;i<n-1;i++)
		{
			cin>>u>>v;
			u--,v--;
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		dfs(0,-1,0);
		
		cout<<ans<<' ';
		if(ans!=0)
		{
			cout<<mini_dist;
		}
		cout<<endl;
	}
	return 0;
}
