#include<bits/stdc++.h>
using namespace std;
const int maxN=4010;
int dp[3][maxN];
int arr[3];
int find(int i,int rem)
{
	if(i==3 && rem==0)
		return 0;
	else if(i==3)
		return -1e5;
		
	if(dp[i][rem]!=-1)
		return dp[i][rem];
		
	int max_val=-1e5;
	for(int j=0;j<=rem/arr[i];j++)
	{
		int a=j+find(i+1,rem-j*arr[i]);
		//cout<<i<<' '<<j<<' '<<a<<' '<<rem-j*arr[i]<<endl;
		if(max_val<a)
			max_val=a;
	}
	dp[i][rem]=max_val;
	return max_val;
}
int main()
{
	int n,a,b,c;
	cin>>n>>arr[0]>>arr[1]>>arr[2];
	memset(dp,-1,sizeof(dp));
	
	cout<<find(0,n)<<endl;
	return 0;
}
