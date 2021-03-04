#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxN=1e5;
int col[maxN];
vector<int> adj[maxN];
bool mark[maxN]={0};
int par[500];

int parent(int i)
{
	if(par[i]==i)
		return i;
		
	par[i]=parent(par[i]);
	return par[i];
}

void dfs(int i,int root)
{
	if(parent(col[i])==parent(col[root]) && mark[i]==0)
	{
		mark[i]=1;
		for(auto ch:adj[i])
		{
			dfs(ch,root);
		}
		
	}
}


int main(){
	cin>>n>>m>>k;
	int sum=0;
	for(int i=0;i<k;i++)
	{
		int temp;
		cin>>temp;
		for(int j=sum;j<sum+temp;j++)
		{
			col[j]=i;	
		}
		sum+=temp;
	}
	
	for(int i=0;i<k;i++)
	{
		par[i]=i;
	}
	
	long long D[k][k];
	
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			D[i][j]=1e12;
		}
		D[i][i]=0;
	}
	
	
	int u,v;
	long long x;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>x,u--,v--;
		if(col[u]==col[v] && x==0)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		else if(col[u]!=col[v])
		{
			D[col[u]][col[v]]=min(D[col[u]][col[v]],x);
			D[col[v]][col[u]]=min(D[col[v]][col[u]],x);
			
			if(x==0)
			{
				adj[u].push_back(v);
				adj[v].push_back(u);
				
				if(parent(col[u])!=parent(col[v]))
				{
					par[col[v]]=par[col[u]];
				}
			}
		}
	}
	set<int> proc;
	for(int i=0;i<n;i++)
	{
		if(mark[i]==0)
		{
			if(proc.find(parent(col[i]))==proc.end())
			{
				proc.insert(parent(col[i]));
				dfs(i,i);
			}
			else
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	
	for(int p=0;p<k;p++)
	{
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				D[i][j]=min(D[i][j],D[i][p]+D[p][j]);
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(D[i][j]!=1e12)
				cout<<D[i][j]<<' ';
			else
				cout<<-1<<' ';
		}
		cout<<endl;
	}
}
