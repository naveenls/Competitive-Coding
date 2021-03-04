#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

int main()
{
	int n,m;
	cin>>n>>m;
	
	string s;
	cin>>s;
	
	if(n-m)
	{
		int mi=0;
		int sum=0;
		
		for(int i=0;i<m;i++)
		{
			sum+= (s[i]=='(' ? 1 : -1);
			mi=min(mi,sum);	
		}
		
		//cout<<mi<<' '<<sum<<endl;
		long long DP[n-m+1][n-m+1];
		
		memset(DP,0,sizeof(DP));
		DP[0][0]=1;
		
		for(int i=0;i<n-m;i++)
		{
			for(int j=0;j<=n-m;j++)
			{
				if(j)
				{
					DP[i+1][j-1]+=DP[i][j];
					DP[i+1][j-1]%=mod;
				}
				if(j<n-m)
				{
					DP[i+1][j+1]+=DP[i][j];
					DP[i+1][j+1]%=mod;	
				}
			}
		}
		/*
		for(int i=1;i<=n-m;i++)
		{
			for(int j=0;j<=n-m;j++)
			{
				cout<<DP[i][j]<<' ';
			}
			cout<<endl;
		}*/
		long long ans=0;
		for(int i=0;i<=n-m;i++)
		{
			for(int j=-mi;j<=i;j++)
			{
				long long val1=DP[i][j];
				long long val2=0;
				
				if(j+sum<=n-m)
				{
					long long len=n-m-i;					
					val2=DP[len][j+sum];	
				}		
				ans=(ans+val1*val2%mod)%mod;
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		int mi=0;
		int sum=0;
		
		for(int i=0;i<m;i++)
		{
			sum+= (s[i]=='(' ? 1 : -1);
			mi=min(mi,sum);	
		}
		
		if(sum==0 &&  mi>=0)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
}
