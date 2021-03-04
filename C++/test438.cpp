#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	string arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int DP[n][m];
	
	for(int i=0;i<m;i++)
	{
		int x=n-1,y=i;
		
		if(arr[x][y]=='1')
		{
			DP[x][y]=1;
		}
		else
		{
			DP[x][y]=0;
		}
		
		x--,y--;
		
		while(x>=0 && y>=0)
		{
			if(arr[x][y]=='1')
			{
				DP[x][y]=1+DP[x+1][y+1];
			}
			else
			{
				DP[x][y]=0;
			}
			x--,y--;
		}
	}
	
	for(int i=n-2;i>=0;i--)
	{
		int x=i,y=m-1;
		
		if(arr[x][y]=='1')
		{
			DP[x][y]=1;
		}
		else
		{
			DP[x][y]=0;
		}
		
		x--,y--;
		
		while(x>=0 && y>=0)
		{
			if(arr[x][y]=='1')
			{
				DP[x][y]=1+DP[x+1][y+1];
			}
			else
			{
				DP[x][y]=0;
			}
			x--,y--;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			DP[i][j]+=j;
		}
		for(int j=m-2;j>=0;j--)
		{
			DP[i][j]=min(DP[i][j],DP[i][j+1]);
		}
	}
	
	long long ans=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int h=DP[i][j]-j;
			if(h>=0)
			{
				ans+=h;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
