#include<bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

const int maxN=1e5;

vector<int> adj[maxN];
vector<long long> edg;

void reset(int n)
{
	edg.clear();
	for(int i=0;i<n;i++)
		adj[i].clear();	
}

long long N;

long long dfs(int i,int p)
{
	long long sz=1;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			long long temp=dfs(ch,i);
			sz+=temp;
			
			edg.push_back(temp*(N-temp));
		}
	}
	
	return sz;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		reset(n);
		N=n;
		
		long long prod[n-1];
		
		int u,v;
		for(int i=0;i<n-1;i++)
		{
			cin>>u>>v,u--,v--;
			
			adj[u].push_back(v);
			adj[v].push_back(u);
			
			prod[i]=1;
		}
		
		dfs(0,-1);
		
		sort(edg.begin(),edg.end(),greater<long long> ());
		
		int m;
		cin>>m;
		
		vector<long long> prime(m);
		
		for(int i=0;i<m;i++)
		{
			cin>>prime[i];
		}
		
		sort(prime.begin(),prime.end(),greater<long long> ());
		
		if(m<=n-1)
		{
			for(int i=0;i<m;i++)
			{
				prod[i]*=prime[i];
			}
		}
		else
		{
			int diff=(m-n+1);
			
			int j=0;
			
			for(int i=0;i<m;i++,j++)
			{
				if(diff)
				{
					prod[j]=(prod[j]*prime[i])%mod;
					diff--;
					j--;
				}
				else
				{
					prod[j]=(prod[j]*prime[i])%mod;
				}
			}
			
		}
		
		long long ans=0;
		
		for(int i=0;i<n-1;i++)
		{
			prod[i]%=mod;
			edg[i]%=mod;
			
			ans=(ans+prod[i]*edg[i]%mod)%mod;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
