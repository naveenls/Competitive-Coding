#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[n],b[n],c[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	
	int DP[n][2];

	DP[n-1][0]=a[n-1];
	DP[n-1][1]=b[n-1];
	
	for(int i=n-2;i>=0;i--)
	{
		DP[i][0]=max(DP[i+1][0]+b[i],DP[i+1][1]+a[i]);
		DP[i][1]=max(DP[i+1][0]+c[i],DP[i+1][1]+b[i]);
	}
	
	cout<<DP[0][0]<<endl;
	return 0;
}
