#include<bits/stdc++.h>
using namespace std;

long long mat[4][4]={{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}};
long long res[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
long long m=1000000007;
void multiply(long long a[4][4],long long b[4][4],long long c[4][4])
{
	long long temp[4][4];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			temp[i][j]=0;
			for(int k=0;k<4;k++)
			{
				temp[i][j]=(temp[i][j]+b[i][k]*c[k][j]%m)%m;
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			a[i][j]=temp[i][j];
		}
	}
}
void power(int y) 
{ 
    while(y>0)
    {
    	if(y%2)
    	{
    		multiply(res,mat,res);
		}
		y/=2;
		multiply(mat,mat,mat);
	}
} 

int main()
{
	int n;
	cin>>n;
	power(n);
	cout<<res[0][0]<<endl;
	return 0;
	
}
