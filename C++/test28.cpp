#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;

	int arr[n+1][m+1][2];
	for(int i=1;i<=n;i+=2)
	{
		for(int j=1;j<m;j++)
		{
			arr[i][j][0]=i;
			arr[i][j][1]=j+1;
		}
		arr[i][m][0]=i+1;
		arr[i][m][1]=m;
	}
	for(int i=2;i<=n;i+=2)
	{
		for(int j=m;j>1;j--)
		{
			arr[i][j][0]=i;
			arr[i][j][1]=j-1;
		}
		arr[i][1][0]=i+1;
		arr[i][1][1]=1;
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<arr[i][j][0]<<' '<<arr[i][j][1]<<endl;
		}
	}
	*/
	int tx,ty,x=1,y=1;
	int temp=k;
	while(k>1)
	{
		cout<<2<<' ';
		cout<<x<<' '<<y<<' ';
		tx=x;
		ty=y;
		x=arr[tx][ty][0];
		y=arr[tx][ty][1];
		//cout<<arr[1][3][0]<<' '<<arr[1][3][1]<<"hi"<<endl;
		cout<<x<<' '<<y<<' '<<endl;
		tx=x;
		ty=y;
		x=arr[tx][ty][0];
		y=arr[tx][ty][1];
		k--;
	}
	int cnt=n*m-(temp-1)*2;
	cout<<cnt<<' ';
	while(cnt)
	{
		cout<<x<<' '<<y<<' ';
		tx=x;
		ty=y;
		x=arr[tx][ty][0];
		y=arr[tx][ty][1];
		cnt--;
	}
	return 0;
}
