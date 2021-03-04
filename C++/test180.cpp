#include<bits/stdc++.h>
using namespace std;

const int maxN = 5010;
int n,T;

double arr[maxN];
int time_l[maxN];

int main()
{
	cin>>n>>T;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i]>>time_l[i];
		arr[i]/=100;
	}
	
	double DP[n+1][T+1];
	
	for(int i=0;i<=n;i++)
		DP[i][0]=0.0;
		
	for(int j=1;j<=T;j++)
		DP[n][j]=0.0;
	
	for(int i=n-1;i>=0;i--)
	{
		
		if(time_l[i]==1)
		{
			for(int j=1;j<=T;j++)
				DP[i][j]=1+DP[i+1][j-1];
				
			continue;
		}
		double prefix=1.0;	
		double ans=0.0;
		
		for(int j=1;j<=T;j++)
		{
			if(j<time_l[i])
			{
				ans=ans*(1-arr[i]) + arr[i]*(DP[i+1][j-1]+1);

				DP[i][j]=ans;
				
				prefix*=(1-arr[i]);
			}
			else if(j==time_l[i])
			{
				ans=ans*(1-arr[i]) + arr[i]*(DP[i+1][j-1]+1);
								
				DP[i][j]=ans-prefix*arr[i]*(1+DP[i+1][j-time_l[i]])+prefix*(1+DP[i+1][j-time_l[i]]);
				prefix*=(1-arr[i]);
			}
			else
			{
				ans=ans*(1-arr[i]) + arr[i]*(DP[i+1][j-1]+1);

				ans-=prefix*arr[i]*(DP[i+1][j-time_l[i]-1]+1);
				
				if(arr[i]!=1.0)
					prefix/=(1-arr[i]);
					
				DP[i][j]=ans-prefix*arr[i]*(DP[i+1][j-time_l[i]]+1)+ prefix*(1+DP[i+1][j-time_l[i]]);
				
				if(arr[i]!=1.0)
					prefix*=(1-arr[i]);

			}
		}
	}

	cout<<fixed<<setprecision(10)<<DP[0][T];
	return 0;
}
