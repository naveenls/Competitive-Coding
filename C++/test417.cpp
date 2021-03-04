#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

vector<int> adj[maxN];
int par[maxN];
int level[maxN];

const int k=18;

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

int get_dist(int i,int j)
{
	int c=get_lca(i,j);
	
	return level[i]+level[j]-2*level[c];
}

long long p=1e9+7;

const int maxV=1000;
long long fac[maxV+1]; 

long long power(long long x, long long y) 
{ 
    long long res = 1; 
  
    x = x % p;  
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
  
long long modInverse(long long n) 
{ 
    return power(n, p-2); 
} 

void nCrModPFermat(long long n) 
{    
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p;   
} 

long long nCr(long long n,long long r)
{
	if (r==0) 
      return 1; 
      
	return (fac[n]* modInverse(fac[r]) % p * 
            modInverse(fac[n-r]) % p) % p; 
}

int main()
{
	cin>>n;
	nCrModPFermat(n);
	
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
	
	map<int,int> mp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				int temp=get_dist(i,j);
				temp=n-1-temp;
				
				mp[temp]++;		
			}
		}
	}
	
	int ans[n]={0};
	
	for(auto ele:mp)
	{
		for(int i=0;i<=ele.first;i++)
		{
			ans[i]=(ans[i]+nCr(ele.first,i)*ele.second%p)%p;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		ans[i]=(n+ans[i]*modInverse(nCr(n-1,i))%p)%p;
		cout<<ans[i]<<' ';
	}

	return 0;
}
