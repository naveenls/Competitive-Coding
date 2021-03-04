#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	long long d[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>d[i][j];
		}
	}
	
	int k;
	cin>>k;
	
	int u,v;
	long long c;
	for(int i=0;i<k;i++)
	{
		cin>>u>>v>>c,u--,v--;
		
		d[u][v]=min(d[u][v],c);
		d[v][u]=min(d[v][u],c);
		
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				long long dist=min(d[i][u]+d[v][j]+d[u][v],d[i][v]+d[u][j]+d[u][v]);
				
				d[i][j]=min(d[i][j],dist);
				d[j][i]=min(d[j][i],dist);
				
				ans+=d[i][j];
			}
		}
		cout<<ans<<' ';
		
	
	}
	return 0;
}
