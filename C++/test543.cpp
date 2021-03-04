#include<bits/stdc++.h>
using namespace std;

int find_par(int i,vector<int> &par)
{
	if(i==par[i])
		return i;
		
	par[i]=find_par(par[i],par);
	return par[i];
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int> adj[n];
		
		int u,v;
		for(int i=0;i<n-1;i++)
		{
			cin>>u>>v;
			u--,v--;
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<int> dsu[n+1];
		dsu[n]=vector<int>(n);
		
		for(int i=0;i<n;i++)
			dsu[n][i]=i;
		
		int p[n];
		int pos[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
			p[i]--;
			
			pos[p[i]]=i;
		}
		
		long long a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
			
		for(int i=0;i<n;i++)
			cin>>b[i];
			
		int day[n];
		memset(day,-1,sizeof(day));
		
		for(int i=n-1;i>=0;i--)
		{
			dsu[i]=dsu[i+1];
			
			for(auto j:adj[p[i]])
			{
				int a=find_par(p[i],dsu[i]);
				int b=find_par(j,dsu[i]);
				
				if(a!=b && pos[j]>i)
				{
					dsu[i][a]=b;
				}
			}
		}
		
		for(int i=0;i<n;i++)
		{
			long long cnt=a[p[i]];
			
			for(int j=0;j<n;j++)
			{
				if(find_par(p[i],dsu[i])==find_par(j,dsu[i]))
				{
					b[j]-=min(b[j],cnt);
					
					if(b[j]==0 && day[j]==-1)
					{
						day[j]=i+1;
					}
				}
			}
		}
		
		for(int i=0;i<n;i++)
			cout<<day[i]<<' ';
			
		cout<<endl;
		
	}
	return 0;
}
