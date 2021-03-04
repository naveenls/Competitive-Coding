#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	long long dist[n][m];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;++j)
		{
			cin>>dist[i][j];
		}
	}
	
	long long maxAS[n][m];
	long long maxAE[n][m];
	
	long long maxBS[n][m];
	long long maxBE[n][m];
	
	maxAS[0][0]=dist[0][0];
	for(int i=1;i<m;i++)
	{
		maxAS[0][i]=dist[0][i]+maxAS[0][i-1];
	}
	for(int i=1;i<n;i++)
	{
		maxAS[i][0]=dist[i][0]+maxAS[i-1][0];
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			maxAS[i][j]=max(dist[i][j]+maxAS[i-1][j],dist[i][j]+maxAS[i][j-1]);
		}
	}
	
	maxAE[n-1][m-1]=dist[n-1][m-1];
	for(int i=m-2;i>=0;i--)
	{
		maxAE[n-1][i]=dist[n-1][i]+maxAE[n-1][i+1];
	}
	for(int i=n-2;i>=0;i--)
	{
		maxAE[i][m-1]=dist[i][m-1]+maxAE[i+1][m-1];
	}
	
	for(int i=n-2;i>=0;i--)
	{
		for(int j=m-2;j>=0;j--)
		{
			maxAE[i][j]=max(dist[i][j]+maxAE[i+1][j],dist[i][j]+maxAE[i][j+1]);
		}
	}
	

	maxBS[n-1][0]=dist[n-1][0];
	for(int i=1;i<m;i++)
	{
		maxBS[n-1][i]=dist[n-1][i]+maxBS[n-1][i-1];
	}
	for(int i=n-2;i>=0;i--)
	{
		maxBS[i][0]=dist[i][0]+maxBS[i+1][0];
	}
	
	for(int i=n-2;i>=0;i--)
	{
		for(int j=1;j<m;j++)
		{
			maxBS[i][j]=max(dist[i][j]+maxBS[i+1][j],dist[i][j]+maxBS[i][j-1]);
		}
	}
	
	maxBE[0][m-1]=dist[0][m-1];
	for(int i=m-2;i>=0;i--)
	{
		maxBE[0][i]=dist[0][i]+maxBE[0][i+1];
	}
	for(int i=1;i<n;i++)
	{
		maxBE[i][m-1]=dist[i][m-1]+maxBE[i-1][m-1];
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=m-2;j>=0;j--)
		{
			maxBE[i][j]=max(dist[i][j]+maxBE[i-1][j],dist[i][j]+maxBE[i][j+1]);
		}
	}
	long long max_val=0;
	
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<m-1;j++)
		{
			long long temp=max(maxAS[i-1][j]+maxAE[i+1][j]+maxBS[i][j-1]+maxBE[i][j+1],maxBE[i-1][j]+maxBS[i+1][j]+maxAS[i][j-1]+maxAE[i][j+1]);
			max_val=max(temp,max_val);
		}
	}
	cout<<max_val<<endl;
	return 0;
}
