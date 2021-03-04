#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n+2];
	arr[0]=0;
	arr[n+1]=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	int DP[n+2],DP1[n+2];
	
	DP[0]=0;
	DP1[n+1]=0;
	
	int ma=0;
	
	for(int i=1;i<=n;i++)
	{
		if(arr[i]>arr[i-1])
		{
			DP[i]=DP[i-1]+1;
		}
		else
		{
			DP[i]=1;
		}
		ma=max(ma,DP[i]);
	}
	
	for(int i=n;i>=1;i--)
	{
		if(arr[i]<arr[i+1])
		{
			DP1[i]=DP1[i+1]+1;
		}
		else
		{
			DP1[i]=1;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(arr[i+1]>arr[i-1])
			ma=max(ma,DP[i-1]+DP1[i+1]);
	}
	cout<<ma<<endl;
	return 0;
}
