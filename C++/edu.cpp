#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		long long x;
		cin>>n>>x;
		
		long long arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		sort(arr,arr+n,greater<long long> ());
		
		int DP[n];
		
		if(arr[0]>=x)
		{
			DP[0]=1;
		}
		else
		{
			DP[0]=0;
		}
		
		for(int i=1;i<n;i++)
		{
			int num=(x+arr[i]-1)/arr[i];
			
			DP[i]=-1;
			if(num>i+1)
			{
				DP[i]=DP[i-1];	
			}
			else if(num==i+1)
			{
				DP[i]=max(1,DP[i-1]);
			}
			else
			{
				DP[i]=max(DP[i-1],1+DP[i-num]);
			}
		}
		cout<<DP[n-1]<<endl;
		
	}
	return 0;
}
