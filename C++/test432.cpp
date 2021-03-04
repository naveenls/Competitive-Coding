#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		long long arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		long long DP[n][2];
		
		DP[0][0]=arr[0];
		DP[0][1]=arr[0];
		
		for(int i=1;i<n;i++)
		{
			long long mi=1e18;
			long long ma=-1e18;
			
			mi=min(mi,DP[i-1][0]-arr[i]);
			mi=min(mi,DP[i-1][0]+arr[i]);
			mi=min(mi,DP[i-1][0]*arr[i]);
			
			mi=min(mi,DP[i-1][1]-arr[i]);
			mi=min(mi,DP[i-1][1]+arr[i]);
			mi=min(mi,DP[i-1][1]*arr[i]);
			
			ma=max(ma,DP[i-1][0]-arr[i]);
			ma=max(ma,DP[i-1][0]+arr[i]);
			ma=max(ma,DP[i-1][0]*arr[i]);
			
			ma=max(ma,DP[i-1][1]-arr[i]);
			ma=max(ma,DP[i-1][1]+arr[i]);
			ma=max(ma,DP[i-1][1]*arr[i]);
			
			DP[i][0]=mi;
			DP[i][1]=ma;
		}
		cout<<DP[n-1][0]<<endl;
	}
	return 0;
}
