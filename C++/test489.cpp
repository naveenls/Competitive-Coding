#include<bits/stdc++.h>
using namespace std;

const int maxN=15;
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
	int n;
	cin>>n;
	
	long long k;
	cin>>k;
	
	N=n+3;
	
	memset(res,0,sizeof(res));
	memset(mat,0,sizeof(mat));
	
	long long a[n],c[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	for(int i=0;i<n;i++)
		cin>>c[i];
		
	for(int i=0;i<n;i++)
	{
		res[i][i]=1;
		
		if(!i)
		{
			for(int j=0;j<n;j++)
				mat[i][j]=c[j];
		}
		else
		{
			mat[i][i-1]=1;
		}
	}
	
	long long p,q,r;
	cin>>p>>q>>r;
	
	if(k<n)
	{
		cout<<a[k]<<endl;
		return 0;
	}
	
	mat[0][n]=p;
	mat[0][n+1]=q;
	mat[0][n+2]=r;
	
	mat[n][n]=1;
	mat[n+1][n]=1;
	mat[n+1][n+1]=1;
	mat[n+2][n+2]=1;
	mat[n+2][n+1]=2;
	mat[n+2][n]=1;
	
	power(k-n+1);
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans=(ans+res[0][i]*a[n-i-1])%mod;
	}
	ans=(ans+res[0][n])%mod;
	ans=(ans+res[0][n+1]*n)%mod;
	ans=(ans+res[0][n+2]*n*n)%mod;
	
	cout<<ans;
	return 0;
}
