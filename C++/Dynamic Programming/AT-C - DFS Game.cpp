#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;
vector<int> adj[maxN];
int DP[maxN];
int sz[maxN] = {0};

void dfs(int i)
{
	sz[i] = 1;
	DP[i] = 0;
	
	vector<pair<int,int> > odd;
	vector<pair<int,int> > even;
	
	for(auto ch:adj[i])
	{
		dfs(ch);
		
		if(sz[ch]%2)
			odd.push_back({DP[ch],sz[ch]});
		else
			even.push_back({DP[ch],sz[ch]});
		
		sz[i] += sz[ch];
	}
	
	if(odd.size() % 2){
		for(auto pr:even)
			DP[i] += max(pr.first, pr.second-pr.first);
	}
	else{
		for(auto pr:even)
			DP[i] += pr.second - pr.first;
	}
	
	if(odd.size())
	{
		vector<pair<int,int> > v;
		
		for(auto pr:odd){
			v.push_back({pr.second-2*pr.first,pr.second - pr.first});
		}
		
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		
		for(int j=0;j<v.size();j++)
		{
			if(j%2 == 0)
			{
				DP[i] += (v[j].second);				
			}
			else
			{
				DP[i] += (v[j].second-v[j].first);				
			}	
		}
	}
	
	DP[i] = sz[i] - DP[i];
	
}
int main()
{
	int n;
	cin>>n;
	
	int par[n];
	par[0] = -1;
	
	for(int i=1;i<n;i++)
	{
		cin>>par[i];
		par[i]--;
		
		adj[par[i]].push_back(i);
	}
	
	dfs(0);

	cout<<DP[0]<<endl;
	
	return 0;
}
