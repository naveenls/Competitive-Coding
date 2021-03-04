#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5;
int arr[maxN+1]={0};	
long long dp[maxN+4]={0};

int main()
{
	int n;
	cin>>n;
	
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr[a]++;
	}
	for(int i=maxN;i>=1;i--)
	{
		dp[i]=max((long long)arr[i]*i+dp[i+2],dp[i+1]);
	}
	cout<<dp[1]<<endl;
	return 0;
	
}
