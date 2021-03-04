#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,p,k;
		cin>>n>>p>>k;
		
		int arr[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		
		sort(arr+1,arr+n+1);
		int DP[n+1];
		DP[0]=0;
		
		for(int i=1;i<k;i++)
		{
			DP[i]=arr[i]+DP[i-1];
		}
		
		for(int i=k;i<=n;i++)
		{
			DP[i]=min(arr[i]+DP[i-1],arr[i]+DP[i-k]);
		}
		
		int ma=0;
		
		for(int i=1;i<=n;i++)
		{
			if(DP[i]<=p)
			{
				ma=i;
			}
		}
		cout<<ma<<endl;
	}
	return 0;
}
