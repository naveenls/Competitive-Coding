#include<bits/stdc++.h>
using namespace std;

const int N=65;
const int maxN=65;

unsigned int mat[maxN][maxN];
unsigned int res[maxN][maxN];

void multiply(unsigned int c[maxN][maxN],unsigned int a[maxN][maxN],unsigned int b[maxN][maxN])
{
	unsigned int temp[N][N];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			temp[i][j]=0;
			
			for(int k=0;k<N;k++)
			{
				temp[i][j]+=a[i][k]*b[k][j];
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

int dir_x[8]={2,2,1,-1,-2,-2,-1,1};
int dir_y[8]={1,-1,2,2,1,-1,-2,-2};

int main()
{
	int k;
	cin>>k;
	
	memset(res,0,sizeof(res));
	memset(mat,0,sizeof(mat));
	
	vector<int> adj[N];
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			int val=8*i+j;
			
			for(int t=0;t<8;t++)
			{
				int x=i+dir_x[t];
				int y=j+dir_y[t];
				
				if(x>=0 && x<8 && y>=0 && y<8)
				{
					adj[val].push_back(x*8+y);
				}
			}
		}
	}
	
	
	for(int i=0;i<N;i++)
	{
		adj[i].push_back(64);
		res[i][i]=1;
		
		for(auto j:adj[i])
		{
			mat[i][j]=1;
		}
	}
	
	power(k+1);
	
	cout<<res[0][64]<<endl;
	
	return 0;
}
