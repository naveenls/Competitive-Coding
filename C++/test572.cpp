#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		int arr[n+2][m+2];
		memset(arr,0,sizeof(arr));
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>arr[i][j];
			}
		}
		
		int left[n+2][m+2];
		int right[n+2][m+2];
		int up[n+2][m+2];
		int down[n+2][m+2];
		
		for(int i=1;i<=n;i++)
		{
			left[i][0]=0;
			right[i][n+1]=0;
		}
		
		for(int j=1;j<=m;j++)
		{
			up[0][j]=0;
			down[m+1][j]=0;
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				left[i][j]=min(arr[i][j],left[i][j-1]+arr[i][j]);
			}
			
			for(int j=m;j>=1;j--)
			{
				right[i][j]=min(arr[i][j],right[i][j+1]+arr[i][j]);
			}
		}
		
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				up[i][j]=min(arr[i][j],up[i-1][j]+arr[i][j]);
			}
			
			for(int i=n;i>=1;i--)
			{
				down[i][j]=min(arr[i][j],down[i+1][j]+arr[i][j]);	
			}
		}
		
		int mi=2e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int v1=min(0,left[i][j-1]);
				int v2=min(0,right[i][j+1]);
				int v3=min(0,up[i-1][j]);
				int v4=min(0,down[i+1][j]);
				
				mi=min(mi,v1+v2+v3+v4+arr[i][j]);
			}
		}
		
		cout<<mi<<endl;
	}
}
