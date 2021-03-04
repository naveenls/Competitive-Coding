#include<bits/stdc++.h>
using namespace std;
const int maxN=2*1e5+10;

vector<int> adj[maxN];
int arr[maxN];
int par[maxN];
int level[maxN];

const int k=19;

int Sparse[maxN][k];
//int nos[maxN][k][101];
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
    		Sparse[i][j]=-1;
    		/*
    		for(int k=1;k<=100;k++)
    			nos[i][j][k]=0;
    		*/
    	}
	}
	
	for(int i=0;i<n;i++)
	{
		Sparse[i][0]=par[i];
		//nos[i][0][arr[i]]=1;
	}
	
	for(int j=1;(1<<j)<n;j++)
	{
		for(int i=0; i<n;i++)
		{
			if(Sparse[i][j-1]!=-1)
			{
				Sparse[i][j]=Sparse[Sparse[i][j-1]][j-1];
				/*
				for(int k=1;k<=100;k++)
				{
					nos[i][j][k]=nos[i][j-1][k]+nos[Sparse[i][j-1]][j-1][k];
				}
				*/
			}
		}
	}
}

int get_val(int p,int q)
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
			p=Sparse[p][i];
		}
	}
	if(p==q)
		return p;
		
	for(int i=log;i>=0;i--)
	{
		if(Sparse[p][i]!=-1 && Sparse[p][i]!=Sparse[q][i])
		{
			p=Sparse[p][i];
			q=Sparse[q][i];
		}
	}
	return par[p];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<maxN;i++)
		{
			adj[i].clear();
		}
		int q;
		cin>>n>>q;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		int a,b;
		for(int i=0;i<n-1;i++)
		{
			cin>>a>>b;
			a--,b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		dfs(0,maxN-3,0);
		BuildTable();
		for(int i=0;i<q;i++)
		{
			cin>>a>>b;
			a--,b--;
			int c=get_val(a,b);
						
			int T=level[b]+level[a]-2*level[c]+1;
			if(T>100)
			{
				cout<<0<<endl;
			}
			else
			{
				set<int> s;
				
				while(a!=c)
				{
					s.insert(a);
					a=par[a];
				}
				
				while(b!=c)
				{
					s.insert(b);
					b=par[b];
				}
				s.insert(c);
				
				vector<int> v;
				for(auto ele:s)
				{
					v.push_back(arr[ele]);
				}
				sort(v.begin(),v.end());
				
				int mi=1e9;
				for(int i=0;i<v.size()-1;i++)
				{
					mi=min(v[i+1]-v[i],mi);
				}
				cout<<mi<<endl;
			}
		}
		
	}
	return 0;
}
