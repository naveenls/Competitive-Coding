#include<bits/stdc++.h>
using namespace std;

map<pair<pair<int,int> ,int>,long long > mp;

map<pair<int,int> , pair<int,int> 
long long mod=1e9+7;

long long find_ans(int m,int n,int k)
{
	if(k==0)
		return 1;
		
	if(min(n/2,m/2)<k)
		return 0;
		
	if(mp.find({{m,n},k})!=mp.end())
		return mp[{{m,n},k}];
		
	long long ans=0;
	for(int i=1;i<=n-2;i++)
	{
		for(int j=1;j<=m-2;j++)
		{
			long long count=(n-1-i)*(m-1-j);
			ans=(ans+count*find_ans(i,j,k-1)%mod)%mod;
		}
	}
	mp[{{m,n},k}]=ans;
	return ans;
}
int main()
{
	int n,m,k;
	
	cin>>n>>m>>k;
	
	cout<<find_ans(n,m,k);
	return 0;
}
