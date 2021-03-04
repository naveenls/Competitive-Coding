#include<bits/stdc++.h>
using namespace std;

long long mat[2][2];
long long res[2][2]={{1,0},{0,1}};

long long mod=1e9+7;
void multiply(long long c[2][2], long long a[2][2], long long b[2][2])
{
	long long temp[2][2];
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			temp[i][j]=0;
			
			for(int k=0;k<2;k++)
			{
				temp[i][j]+=a[i][k]*b[k][j];
				temp[i][j]%=mod;
			}
		}
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
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
	long long n;
	cin>>n;
	
	mat[0][0]=19;
	mat[1][1]=20;
	mat[0][1]=6;
	mat[1][0]=7;
		
	power(n);
	cout<<res[0][0]<<endl;
	return 0;
}
