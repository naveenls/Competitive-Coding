#include<bits/stdc++.h>
using namespace std;

long long ans=0;

int n;
int m;

const int maxN=2000;
string arr[maxN];

int DP[maxN][maxN];
int DP1[maxN][maxN];

void count()
{
	memset(DP,0,sizeof(DP));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			DP[i][j]=1;
				
			if(j && arr[i][j]==arr[i][j-1])
				DP[i][j]+=DP[i][j-1];
		}
		
		int temp=0;
		for(int j=m-1;j>=0;j--)
		{
			if(j<m-1 && arr[i][j]==arr[i][j+1])
				temp++;
			else
				temp=1;

			DP[i][j]=min(DP[i][j],temp);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			DP1[i][j]=DP[i][j];
			
			if(i && arr[i][j]==arr[i-1][j])
				DP1[i][j]=min(DP1[i][j],DP1[i-1][j]+1);
			else
				DP1[i][j]=min(DP1[i][j],1);				
		}
	}
	
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<m;j++)
		{	
			if(i<n-1 && arr[i][j]==arr[i+1][j])
				DP[i][j]=min(DP[i+1][j]+1,DP[i][j]);
			else
				DP[i][j]=min(DP[i][j],1);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			long long val=min(DP[i][j],DP1[i][j]);				
			ans+=val;
		}
	}
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	count();
	cout<<ans<<endl;
	return 0;
}
