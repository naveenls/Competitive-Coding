#include<bits/stdc++.h>
using namespace std;

const int maxN=31;
const int maxK=51;

long long DP[maxN][maxN][maxK];

long long find_ans(int n,int m,int k)
{
	if(k==0)
		return 0;
		
	if(n*m==k)
	{
		return 0;
	}
	
	if(DP[n][m][k]!=-1)
		return DP[n][m][k];
		
	long long ans=1e18;
	for(int i=1;i<=m-1;i++)
	{
		int seg1=n*i;
		int seg2=n*(m-i);
		
		for(int p=0;p<=k;p++)
		{
			if(p<=seg1 && k-p<=seg2)
			{
				ans=min(ans,n*n+find_ans(n,i,p)+find_ans(n,m-i,k-p));
			}
		}
	}
	
	for(int i=1;i<=n-1;i++)
	{
		int seg1=m*i;
		int seg2=m*(n-i);
		
		for(int p=0;p<=k;p++)
		{
			if(p<=seg1 && k-p<=seg2)
			{
				ans=min(ans,m*m+find_ans(i,m,p)+find_ans(n-i,m,k-p));
			}
		}
	}
	
	DP[n][m][k]=ans;
	return ans;
}
int main()
{
	memset(DP,-1,sizeof(DP));
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		
		cout<<find_ans(n,m,k)<<endl;
	}
	return 0;
}
