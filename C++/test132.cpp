#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5;
vector<int> adj[maxN];

long long arr[maxN];
int parent[maxN];

long long max_inc[maxN];
long long max_dec[maxN];

void dfs(int i,int p)
{
	long long sum=0;
	max_inc[i]=0;
	max_dec[i]=0;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			dfs(ch,i);
			max_inc[i]=max(max_inc[ch],max_inc[i]);
			max_dec[i]=max(max_dec[ch],max_dec[i]);
		}
	}	
	sum=max_inc[i]-max_dec[i];
	
	if(arr[i]+sum>0)
	{
		max_dec[i]+=(arr[i]+sum);
	}
	else
	{
		max_inc[i]+=-(arr[i]+sum);
	}
}
int main()
{
	int n;
	cin>>n;
	
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	dfs(0,-1);
	cout<<max_inc[0]+max_dec[0];
	return 0;
}
