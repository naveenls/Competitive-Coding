#include<bits/stdc++.h>
using namespace std;
const int maxN=110;
const int maxK=110;
const int maxD=110;
long long mod=1000000007 ;
int n,k,d;
long long DP[maxN][maxK];

long long find_ans(int i,int sum,int mx)
{
	if(DP[i][sum]!=-1)
		return DP[i][sum];
		
	DP[i][sum]=0;
	for(int j=1;j<mx;j++)
	{
		int val=sum-i;
		if(val>0)
		{
			DP[i][sum]=(DP[i][sum]+i*find_ans(i+1,val,mx))%mod;
		}
		else if(val==0)
		{
			DP[i][sum]=(DP[i][sum]+i)%mod;
		}
	}
	return DP[i][sum];
}
int main()
{
	cin>>n>>k>>d;
	memset(DP,-1,sizeof(DP));
	long long ans=find(1,n,k+1);
	memset(DP,-1,sizeof(DP));
	ans=(ans-find(1,n,d)+mod)%mod;
	cout<<ans<<endl;
	return 0;
	
}
