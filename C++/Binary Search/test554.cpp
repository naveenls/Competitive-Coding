#include<bits/stdc++.h>
using namespace std;
 

int main()
{
  	int r,c;
  	cin>>r>>c;
  	
  	long long arr[r][c];
  	memset(arr,0,sizeof(arr));
  	
  	int k;
  	cin>>k;
  	
  	int a,b;
  	long long val;
  	
  	for(int i=0;i<k;i++)
  	{
  		cin>>a>>b>>val;
		a--,b--;
		
		arr[a][b]=val;	
	}
	
	long long DP[r][c][4];

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			for(int k=0;k<4;k++)
				DP[i][j][k]=-1e18;
		}
	}
	
	DP[0][0][0]=0;
	DP[0][0][1]=arr[0][0];
	DP[0][0][2]=-1e18;
	DP[0][0][3]=-1e18;
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i)
			{
				for(int l=0;l<4;l++)
				{
					DP[i][j][0]=max(DP[i][j][0],DP[i-1][j][l]);
					DP[i][j][1]=max(DP[i][j][1],arr[i][j]+DP[i-1][j][l]);
				}
			}
			
			if(j)
				DP[i][j][0]=max(DP[i][j][0],DP[i][j-1][0]);
				
			for(int k=1;k<4;k++)
			{
				if(j)
				{
					DP[i][j][k]=max(DP[i][j][k],arr[i][j]+DP[i][j-1][k-1]);
					DP[i][j][k]=max(DP[i][j][k],DP[i][j-1][k]);
				}
			}
		}
	}
	
	long long ma=0;
	for(int k=0;k<4;k++)
		ma=max(ma,DP[r-1][c-1][k]);
		
	cout<<ma<<endl;
  	return 0;
}
