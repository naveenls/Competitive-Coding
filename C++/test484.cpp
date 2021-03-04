#include<bits/stdc++.h>
using namespace std;

long double mat[2][2];
long double res[2][2]={{1,0},{0,1}};

void multiply(long double c[2][2], long double a[2][2], long double b[2][2])
{
	long double temp[2][2];
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			temp[i][j]=0;
			
			for(int k=0;k<2;k++)
			{
				temp[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			c[i][j]=temp[i][j];
	}
}
void power(int y) 
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
	long double p;
	cin>>n>>p;
	
	mat[0][0]=1-p;
	mat[1][1]=1-p;
	mat[0][1]=p;
	mat[1][0]=p;
		
	power(n);
	cout<<fixed<<setprecision(10)<<res[0][0]<<endl;
	return 0;
}
