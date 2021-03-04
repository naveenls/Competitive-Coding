#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5;
vector<pair<int,long long> > adj[maxN];
long long sum1=0;
long long sum2=0;

int t_ver;

int dfs(int i,int p)
{
	int size=0;
	
	for(auto ch:adj[i])
	{
		if(ch.first!=p)
		{
			int temp=dfs(ch.first,i);
			if(temp%2==0)
			{
				sum1-=ch.second;
			}
			
			sum2+=ch.second*min(temp,t_ver-temp);
			
			size+=temp;
		}
	}
	
	return size+1;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		t_ver=2*n;
		
		for(int i=0;i<2*n;i++)
		{
			adj[i].clear();	
		}
		
		sum1=sum2=0;
		
		int u,v;
		long long w;
		
		for(int i=0;i<2*n-1;i++)
		{
			cin>>u>>v>>w;
			u--,v--;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
			
			sum1+=w;	
		}
		
		dfs(0,-1);
		
		cout<<sum1<<' '<<sum2<<endl;
	}
	return 0;
}
