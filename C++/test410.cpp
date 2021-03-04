#include<bits/stdc++.h>
using namespace std;

const int maxN=5001;
int DP[maxN][maxN];

int n,k;
int a[maxN],b[maxN],c[maxN];
vector<int> adj[maxN];
int nxt[maxN]={0};

int find_max(int i ,int prev)
{
	if(i==n)
	{
		if(prev<0)
			return -1e9;
		else
			return 0;
	}

	if(prev<a[i])
	{
		return -1e9;
	}
	
	if(DP[i][prev]!=-1)
		return DP[i][prev];
		
	int ans=-1e9;
	
	ans=max(ans,find_max(i+1,prev+b[i]));

	int sum=0;
	int cnt=0;
	for(auto ch:adj[i])
	{
		sum+=ch;
		cnt++;
		
		ans=max(ans,sum+find_max(i+1,prev+b[i]-cnt));
	}
	
	DP[i][prev]=ans;
	return ans;
}
int main()
{
	int m;
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		nxt[i]=i;
	}
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v,u--,v--;	
		nxt[v]=max(nxt[v],u);
	}
	
	for(int i=0;i<n;i++)
	{
		adj[nxt[i]].push_back(c[i]);	
	}
	
	for(int i=0;i<n;i++)
	{
		sort(adj[i].begin(),adj[i].end(),greater<int> ());
	}
	
	memset(DP,-1,sizeof(DP));
	
	int temp=find_max(0,k);
	if(temp<0)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<temp<<endl;
	}
}
