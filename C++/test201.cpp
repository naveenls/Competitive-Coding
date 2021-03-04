#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	int brr[n][m];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>brr[i][j];
		}
	}
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			if(arr[i][j]!=brr[i][j])
			{
				arr[i][j]=1-arr[i][j];
				arr[i+1][j]=1-arr[i+1][j];
				arr[i][j+1]=1-arr[i][j+1];
				arr[i+1][j+1]=1-arr[i+1][j+1];
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(arr[i][m-1]!=brr[i][m-1])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(arr[n-1][i]!=brr[n-1][i])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}
