#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long arr[n][n];
	long long dia1[2*n+10];
	long long dia2[2*n+10];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
			dia1[i+j]+=arr[i][j];
			dia2[i-j+n]+=arr[i][j];
		}
	}
	long long sum[2];
	sum[0]=-1;
	sum[1]=-1;
	int x[2];
	int y[2];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dia1[i+j]+dia2[i-j+n]-arr[i][j]>sum[(i+j)&1])
			{
				sum[(i+j)&1]=dia1[i+j]+dia2[i-j+n]-arr[i][j];
				x[(i+j)&1]=i;
				y[(i+j)&1]=j;
		   }
		}
	}
	cout<<sum[0]+sum[1]<<endl;
	x[0]++,y[0]++,x[1]++,y[1]++;
	cout<<x[0]<<' '<<y[0]<<' '<<x[1]<<' '<<y[1]<<endl;
	return 0;
}
