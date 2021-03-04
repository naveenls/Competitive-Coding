#include<bits/stdc++.h>
using namespace std;

const int maxN=100;

int arr[maxN];
int DP[maxN][maxN+1];
int changes[maxN][maxN];


int n,k;

int find_min(int l,int rem)
{
	if(l==n)
	{
		return 0;
	}
	if(rem<0)
	{
		return 1e9;
	}
	
	if(DP[l][rem]!=-1)
	{
		return DP[l][rem];
	}
	
	int ans=n+1;
	
	for(int i=l;i<n;i++)
	{
		ans=min(ans,changes[l][i] + find_min(i+1,rem-1));
	}
	
	DP[l][rem]=ans;
	return ans;
}
void solve()
{
	cin>>n>>k;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	memset(DP,-1,sizeof(DP));
	
	int cnt[1001]={0};
	
	for(int i=0;i<n;i++)
	{
		int cnt[1001]={0};
		multiset<int> freq(cnt,cnt+1001);
		
		for(int j=i;j<n;j++)
		{
			freq.erase(freq.find(cnt[arr[j]]));
			cnt[arr[j]]++;
			freq.insert(cnt[arr[j]]);
			
			changes[i][j]=(j-i+1) - *freq.rbegin();
		}
	}
	
	cout<<find_min(0,k)<<endl;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve(); 
	}
	return 0;
}
