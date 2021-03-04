#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr[i]--;	
	}
	
	long long DP[n]={0};
	for(int i=0;i<n;i++)
	{
		if(i==arr[i])
			DP[i]=1;
		
		else
		{
			for(int j=arr[i];j<i;++j)
			{
				DP[i]=(DP[i]+DP[j])%mod;
			}
			DP[i]=(DP[i]+(long long)(i-arr[i]+1))%mod;
		}
	}
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans=(ans+DP[i])%mod;
	}
	ans=(ans+n)%mod;
	cout<<ans<<endl;
	return 0;
}
