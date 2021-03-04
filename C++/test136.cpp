#include<bits/stdc++.h>
using namespace std;
const int maxN=2000;
int n;
long long d;
vector<int> adj[maxN];
long long arr[maxN];
long long mod=1e9+7;

long long dfs(int i,int p,int root)
{
	if(arr[i]>arr[root]+d || arr[i]<arr[root])
		return 0;
		
	else if(arr[i]==arr[root] && i<root)
	{
		return 0;
	}
	else
	{
		long long res=1;
		for(auto ch:adj[i])
		{
			if(ch!=p)
			{
				res=(res*(dfs(ch,i,root)+1))%mod;
			}
		}
		return res;
	}
}
int main()
{
	cin>>d>>n;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b,a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans=(ans+dfs(i,-1,i))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
