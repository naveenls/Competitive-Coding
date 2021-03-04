#include<bits/stdc++.h>
using namespace std;

const int maxN=100;
int N;

long long mat[maxN][maxN];
long long res[maxN][maxN];

long long mod=1e9+7;
void multiply(long long c[maxN][maxN], long long a[maxN][maxN], long long b[maxN][maxN])
{
	long long temp[N][N];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			temp[i][j]=0;
			
			for(int k=0;k<N;k++)
			{
				temp[i][j]+=a[i][k]*b[k][j];
				temp[i][j]%=mod;
			}
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			c[i][j]=temp[i][j];
	}
}
void power(long long y) 
{
    while (y > 0) 
    { 
        if (y & 1) 
        	multiply(res,res,mat);

        y = y>>1;
        multiply(mat,mat,mat);
    } 
}

int main()
{
	int n,m;
	cin>>n>>m;
	N=n;
	
	vector<int> adj[n];

	int k;
	cin>>k;
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		u--,v--;
		
		adj[u].push_back(v);
	}
	memset(res,0,sizeof(res));
	memset(mat,0,sizeof(mat));
	
	for(int i=0;i<n;i++)
	{
		res[i][i]=1;
		
		for(auto ele: adj[i])
			mat[i][ele]=1;
	}
	
	power(k);
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans+=res[i][j];
			ans%=mod;
		}
	}
	
	cout<<ans;
	return 0;
}
