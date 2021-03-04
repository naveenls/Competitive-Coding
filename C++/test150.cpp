#include<bits/stdc++.h>
using namespace std;

long long m;

int main()
{
	int n,_h;
	cin>>n>>_h;
	
	unsigned long long DP[n+1][n+1];
	
	memset(DP,0,sizeof(DP));

	DP[1][1]=1;
	DP[0][0]=1;
	
	for(int h=2;h<=n;h++)
	{
		for(int num=1;num<=n;num++)
		{			
			for(int j=0;j<num;j++)
			{
				for(int h1=0;h1<=h-1;h1++)
				{
					DP[num][h]+=(DP[j][h-1]*DP[num-1-j][h1]);
				}
				
				for(int h1=0;h1<=h-1;h1++)
				{
					DP[num][h]+=(DP[j][h1]*DP[num-1-j][h-1]);
				}
				
				DP[num][h]-=DP[j][h-1]*DP[num-1-j][h-1];
			}
			//cout<<DP[num][h]<<' ';
		}
		
	}
	/*
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<DP[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	unsigned long long ans=0;
	for(int i=_h;i<=n;i++)
	{
		ans+=DP[n][i];
	}
	cout<<ans<<endl;
}
