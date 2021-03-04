#include<bits/stdc++.h>
using namespace std;

const int maxN=200;
int N;

long long mod=1e9+7;

long long temp[30][maxN][maxN];

void multiply(int ind)
{
	long long tt[N][N];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			tt[i][j]=0;
			
			for(int k=0;k<N;k++)
			{
				tt[i][j]+=temp[ind-1][i][k]*temp[ind-1][k][j];
				tt[i][j]%=mod;
			}
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			temp[ind][i][j]=tt[i][j];
	}
}

void multiply1(long long res[maxN][maxN],int ind)
{
	long long tt[N][N];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			tt[i][j]=0;
			
			for(int k=0;k<N;k++)
			{
				tt[i][j]+=res[i][k]*temp[ind][k][j];
				tt[i][j]%=mod;
			}
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			res[i][j]=tt[i][j];
	}
}

vector<int> adj[maxN];

int main()
{
	int n,q,m;
	cin>>n>>m>>q;
	N=n;
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		u--,v--;
		
		adj[u].push_back(v);
	}

	const int maxK=1e9;
	
	memset(temp,0,sizeof(temp));
	
	for(int i=0;i<N;i++)
	{
		for(auto ele:adj[i])
		{
			temp[0][i][ele]=1;
		}
	}
	
	for(int i=1;i<30;i++)
	{
		multiply(i);
	}
	
	int k;
	int s[q],t[q];
		
	for(int i=0;i<q;i++)
	{
		cin>>s[i]>>t[i]>>k;
		s[i]--,t[i]--;
		
		long long DP[n]={0};
		DP[s[i]]=1;
		
		int ind=0;
		while(k)
		{
			if(k%2)
			{
				long long new_dp[n]={0};
				
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						new_dp[i]=(new_dp[i]+DP[j]*temp[ind][j][i])%mod;
					}
				}
				
				for(int i=0;i<n;i++)
					DP[i]=new_dp[i];
			}
			ind++;
			k/=2;
		}
		
		cout<<DP[t[i]]<<endl;
	}
	
	return 0;
}
