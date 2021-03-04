#include<bits/stdc++.h>
using namespace std;

const int maxN=100;
int N;

long long mat[maxN][maxN];
long long res[maxN][maxN];

void multiply(long long c[maxN][maxN], long long a[maxN][maxN], long long b[maxN][maxN])
{
	long long temp[N][N];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			temp[i][j]=3*1e18;
			
			for(int k=0;k<N;k++)
			{
				if(a[i][k]!=3*1e18 && b[k][j]!=3*1e18)
					temp[i][j]=min(temp[i][j],a[i][k]+b[k][j]);
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
	
	vector<pair<int,long long> > adj[n];

	int k;
	cin>>k;
	
	int u,v;
	long long c;
	
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		u--,v--;
		cin>>c;
			
		adj[u].push_back({v,c});
	}
	memset(res,0,sizeof(res));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			mat[i][j]=3*1e18;
	}
	
	for(int i=0;i<n;i++)
	{
		res[i][i]=1;
		
		for(auto ele: adj[i])
			mat[i][ele.first]=ele.second;
	}
	
	power(k);
	
	long long ans=3*1e18;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans=min(res[i][j],ans);
		}
	}
	
	if(ans>1e18)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	cout<<ans;
	return 0;
}
