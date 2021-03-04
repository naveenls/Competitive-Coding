#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	const int maxN=10001;
	
	long long DP[n][maxN];
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<maxN;j++)
		{
			DP[i][j]=0;
		}
		DP[i][0]=1;
		DP[i][arr[i]]=1;
		
		long long sum=arr[i];
		
		for(int j=i+1;j<n;j++)
		{
			sum+=arr[j];
			
			for(int k=0;k<maxN;k++)
			{
				DP[j][k]=DP[j-1][k];
				
				if(k>=arr[j])
					DP[j][k]=(DP[j][k]+DP[j-1][k-arr[j]])%mod;
			}
			
			if(sum%2==0)
			{
				long long val=sum/2;
				
				ans=(ans+DP[j][val])%mod;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
