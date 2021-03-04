#include<bits/stdc++.h>
using namespace std;

const int maxK=2000;
long long p_sum[maxK+1];
int val[maxK+1];

long long DP[maxK+1];

int k;

long long find_max(int start)
{
	if(start>k)
		return 0;
		
	if(DP[start]!=-1)
	{
		return DP[start];
	}
	
	long long ans=1e18;
	for(int j=start;j<=k;j++)
	{
		int len=j-start+1;
		
		len=val[len];
		
		long long value=p_sum[j] - p_sum[start+len-1];
		ans=min(ans,value+find_max(j+1));
	}
	DP[start]=ans;
	return ans;
}
int main()
{
	int n,m;
	cin>>n>>m>>k;
	
	long long arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	
	
	memset(val,0,sizeof(val));
	memset(DP,-1,sizeof(DP));
	
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		if(x<=k)
		{
			val[x]=max(val[x],y);
		}
	}
	
	p_sum[0]=0;
	
	for(int i=1;i<=k;i++)
	{
		p_sum[i]=p_sum[i-1]+arr[i-1];
	}
	
	cout<<find_max(1);
	return 0;
}
