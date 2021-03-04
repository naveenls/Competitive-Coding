#include<bits/stdc++.h>
using namespace std;
const int maxN=5010;
const int maxK=5010;

long long dp[maxK][maxN];
bool flag[maxK][maxN];
int n,m,k;

long long find_max(long long prefix[],int seg,int pos)
{
	if(seg==k)
		return 0;
	
	if(flag[seg][pos])
		return dp[seg][pos];
	
	dp[seg][pos]=-LONG_MAX;
	for(int i=pos;i<n-m*(k-seg)+1;i++)
	{
		int l=i-1;
		int r=i+m-1;
		long long sum=prefix[r];
		if(l>=0)
			sum-=prefix[l];
		
		sum=sum+find_max(prefix,seg+1,r+1);
		//cout<<seg<<' '<<pos<<' '<<sum<<endl;
		dp[seg][pos]=max(dp[seg][pos],sum);
	}
	flag[seg][pos]=1;
	return dp[seg][pos];
}
int main()
{
	
	cin>>n>>m>>k;
	long long arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	memset(flag,0,sizeof(flag));
	long long prefix[n];
	prefix[0]=arr[0];
	for(int i=1;i<n;i++)
		prefix[i]=arr[i]+prefix[i-1];
	cout<<find_max(prefix,0,0)<<endl;	
	return 0;
}
