#include<bits/stdc++.h>
using namespace std;

map<pair<int,int> ,int > mp;
map<int,pair<int,int> > inv_mp;

long long mod=1e9+7;

const int N=7;

void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) 
{ 
    int i = 0, j = 0; 
  
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
            if (row != p && col != q) 
            { 
                temp[i][j++] = mat[row][col]; 
  
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 

int determinantOfMatrix(int mat[N][N], int n) 
{ 
    int D = 0;
  
    if (n == 1) 
        return mat[0][0]; 
  
    int temp[N][N];
  
    int sign = 1;
  
    for (int f = 0; f < n; f++) 
    { 
        getCofactor(mat, temp, 0, f, n); 
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1); 
  
        sign = -sign; 
    } 
  
    return D;
}

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
} 

long long modInverse(long long a) 
{ 
    return power(a, mod-2);
} 

int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	
	int cnt=0;
	
	int arr[n][n]={0};
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			mp[{i,j}]=cnt;
			inv_mp[cnt]={i,j};
			
			cnt++;
		}
	}
	
	int initial=0;
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		u--,v--;
		
		arr[u][v]=1;
		arr[v][u]=1;
		
		int ind=mp[{min(u,v),max(u,v)}];
		initial=initial | (1<<ind);
	}
	
	int size=n*(n-1)/2;
	
	long long num[size+1]={0};
	
	int mat[8][8];
	
	for(int mask=0;mask<(1<<size);mask++)
	{
		memset(mat,0,sizeof(mat));
		
		int cnt=0;
		
		for(int i=0;i<size;i++)
		{
			if(mask&(1<<i))
			{
				cnt++;
				
				u=inv_mp[i].first;
				v=inv_mp[i].second;
				
				mat[u][v]=1;
				mat[v][u]=1;

				mat[u][u]++;
				mat[v][v]++;
			}
		}

		int temp[7][7];
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(i!=j)
					temp[i-1][j-1]=-mat[i][j];
				else
					temp[i-1][j-1]=mat[i][j];
			}
		}
		
		num[cnt]+=(mat[0][0])*determinantOfMatrix(temp,n-1);
		num[cnt]%=mod;
	}
	
	int ans[101]={0};
	
	for(int i=0;i<=size;i++)
	{
		ans[i]=num[i];
	}
	
	for(int i=2;i<=100;i++)
	{
		ans[i]=(ans[i-2]+num[i])%mod;
	}
	
	int t;
	while(q--)
	{
		cin>>t;
		
		long long a=power(size,t);
		
		cout<<(ans[t]*modInverse(a))%mod<<endl;
	}
	
	return 0;
}
