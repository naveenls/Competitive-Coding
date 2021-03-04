#include<bits/stdc++.h>

using namespace std;

const int maxN=1e5;
vector<int> adj[maxN];
int ini[maxN];
int final[maxN];

long long num_inv[maxN]={0};
long long ch_num_inv[maxN]={0};

bool col[maxN]={0};
vector<int> ans;
void dfs(int i=0)
{
	col[i]=1;
	
	ini[i]=(ini[i]+num_inv[i]%2)%2;
	
	int inv=0;
	if(ini[i]!=final[i])
	{
		inv=1;
		ans.push_back(i+1);
	}
	
	for(auto ch:adj[i])
	{
		if(!col[ch])
		{
			num_inv[ch]=ch_num_inv[i];
			ch_num_inv[ch]=nim_inv[i]+inv;
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	int u,v;
	for(int i=0;i<n;i++)
	{
		cin>>u>>v,u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}
	for(int i=0;i<n;i++)
	{
		cin>>ini[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>final[i];
	}
	dfs();
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
	return 0;
}
