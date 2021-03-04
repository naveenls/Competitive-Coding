#include<bits/stdc++.h>
using namespace std;

const int maxN=5*1e5;

vector<int> adj[maxN];
int l[maxN],r[maxN];

int R=1;

void dfs(int i,int p,int L)
{
	int num_child=adj[i].size();
	if(p!=-1)
	{
		num_child--;
	}
	
	l[i]=L;
	r[i]=R+num_child+1;
	
	R=r[i];
	
	int cnt=1;
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			dfs(ch,i,r[i]-cnt);
			cnt++;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--,y--;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(0,-1,1);
	
	for(int i=0;i<n;i++)
	{
		cout<<l[i]<<' '<<r[i]<<endl;
	}
	return 0;
}
