#include<bits/stdc++.h>
using namespace std;

const int maxN=2e6+1;

bool check(int DP[],int i,int k)
{
	int ma=0;
	
	for(int j=i;j<maxN;j+=i)
	{
		if(DP[j]!=-1)
		{
			int cnt=(i-(j-DP[i])%i)%i;
			ma=max(ma,cnt);
		}
	}
	
	return ma<=k;
}
int main()
{
	int n,k,a;
	cin>>n>>k;
	
	int mi=1e6;
	
	int arr[maxN]={0};
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr[a]=1;
		
		mi=min(mi,arr[i]);
	}
	
	int DP[maxN];
	
	DP[0]=-1;
	for(int i=1;i<maxN;i++)
	{
		if(arr[i-1])
		{
			DP[i]=i-1;
		}
		else
		{
			DP[i]=DP[i-1];
		}
	}
	
	int ans=1;
	
	for(int i=1;i<=mi;i++)
	{
		if(check(DP,i,k))
		{
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
