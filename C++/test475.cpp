#include<bits/stdc++.h>
using namespace std;

const int maxN=2000;
int t[maxN];
long long c[maxN];

int n;

long long DP[maxN][4020];

long long min_val(int i,int rem)
{
	rem=max(rem,-2000);
	rem=min(rem,2000);
	
	if(i==n)
	{
		if(rem>=0)
		{
			return 0;
		}
		else
		{
			return 1e18;
		}
	}
	
	int temp_rem=rem+2000;
	
	if(DP[i][temp_rem]!=-1)
		return DP[i][temp_rem];
		
	long long ans=min_val(i+1,rem-1);
	ans=min(ans,c[i]+min_val(i+1,rem+t[i]));
	
	DP[i][temp_rem]=ans;
	
	return ans;
}
int main()
{
	cin>>n;
	
	memset(DP,-1,sizeof(DP));
	
	for(int i=0;i<n;i++)
		cin>>t[i]>>c[i];
		
	cout<<min_val(0,0);
	return 0;
}
