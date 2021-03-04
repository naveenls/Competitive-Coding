#include<bits/stdc++.h>
using namespace std;

const int maxN=100;

vector<int> adj[maxN];
int par[maxN];
int level[maxN];

const int k=7;

int LCA[maxN][k];
int n;

void dfs(int i,int p,int l)
{
	par[i]=p;
	level[i]=l;
	for(auto ch:adj[i])
	{
		if(ch!=p)
			dfs(ch,i,l+1);
	}
}

void BuildTable()
{        
    for(int i=0;i<n;i++)
    {
    	for(int j=0;(1<<j)<n;j++)
    	{
    		LCA[i][j]=-1;
    	}
	}
	
	for(int i=0;i<n;i++)
	{
		LCA[i][0]=par[i];
	}
	
	for(int j=1;(1<<j)<n;j++)
	{
		for(int i=0; i<n;i++)
		{
			if(LCA[i][j-1]!=-1)
			{
				LCA[i][j]=LCA[LCA[i][j-1]][j-1];
			}
		}
	}
}

int get_lca(int p,int q)
{
	int temp;
	if(level[p]<level[q])
	{
		temp=p;
		p=q;
		q=temp;
	}
	int log;
	for(log=1;(1<<log)<=level[p];log++);
	log--;
	
	for(int i=log;i>=0;i--)
	{
		if(level[p]-(1<<i)>=level[q])
		{
			p=LCA[p][i];
		}
	}
	if(p==q)
		return p;
		
	for(int i=log;i>=0;i--)
	{
		if(LCA[p][i]!=-1 && LCA[p][i]!=LCA[q][i])
		{
			p=LCA[p][i];
			q=LCA[q][i];
		}
	}
	return par[p];
}

int find_dist(int i,int j)
{
	int k=get_lca(i,j);
	
	return level[i]+level[j]-2*level[k]+1;	
}

bool is_prime[101];

void calc_prime()
{
	for(int i=2;i<=100;i++)
	{
		is_prime[i]=1;
		for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
				is_prime[i]=0;
		}		
	}
}

int main()
{
	int t;
	cin>>t;
	
	calc_prime();
	
	while(t--)
	{
		cin>>n;
		
		long long ans[n];
		
		for(int i=0;i<n;i++)
		{
			adj[i].clear();
			ans[i]=1;
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
		BuildTable();
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int val=find_dist(i,j);
				
				//cout<<i<<' '<<j<<' '<<val<<endl;
				if(is_prime[val])
				{
					int k=get_lca(i,j);
					
					long long mi_val=3*1e18;
					int ind;
					
					int tt=i;
					bool flag=0;
					
					while(tt!=par[k])
					{
						if(ans[tt]%val==0)
						{
							flag=1;
							break;	
						}
						
						if(mi_val>ans[tt])
						{
							mi_val=ans[tt];
							ind=tt;
						}
						tt=par[tt];
					}
					
					tt=j;
					while(tt!=par[k])
					{
						if(ans[tt]%val==0)
						{
							flag=1;
							break;	
						}
						
						if(mi_val>ans[tt])
						{
							mi_val=ans[tt];
							ind=tt;
						}
						tt=par[tt];
					}
					
					if(!flag)
					{
						ans[ind]*=val;
					}
				}
			}
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
