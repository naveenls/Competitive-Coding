#include<bits/stdc++.h>
using namespace std;

long long mod =1000000007;

long long arr[2][2]={{3,1},{1,3}};
long long res[2][2]={{1,0},{0,1}};

void multiply(long long a[2][2],long long b[2][2],long long c[2][2])
{
	long long temp[2][2];
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			temp[i][j]=0;
			for(int k=0;k<2;k++)
			{
				temp[i][j]=(temp[i][j]+b[i][k]*c[k][j]%mod)%mod;
			}
		}
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			a[i][j]=temp[i][j];
			//cout<<arr[i][j]<<' ';
		}
		//cout<<endl;
	}
}
void power(long long n)
{
	while(n)
	{
		if(n%2)
		{
			multiply(res,res,arr);
		}
		n/=2;
		multiply(arr,arr,arr);
	}
}

int main()
{
	long long n;
	cin>>n;
	
	power(n);
	cout<<res[0][0]<<endl;
	return 0;
}
