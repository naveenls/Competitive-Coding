#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5;

vector<int> adj[maxN];

void dfs(int i)
{
	for(auto ch:adj[i])
	{
		cout<<i+1<<' '<<ch+1<<endl;
	}
	for(auto ch:adj[i])
		dfs(ch);
}
int main()
{
	int n,k;
	cin>>n>>k;
	
	int deg[n]={0};
	
	map<int,vector<int> > mp;
	int cnt=0;	
	int root;
	
	int a;
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		
		if(a==0)
		{
			cnt++;
			root=i;
		}
		mp[a].push_back(i);	
	}

	if(cnt!=1)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	for(int d=1;d<mp.size();d++)
	{
		if(mp.find(d)==mp.end() || mp.find(d-1)==mp.end())
		{
			cout<<-1<<endl;
			return 0;
		}
		
		int start=0;
		
		for(auto ind:mp[d])
		{
			if(deg[mp[d-1][start]]==k)
				start++;
			
			if(start==mp[d-1].size())
			{
				cout<<-1<<endl;
				return 0;
			}
			
			deg[mp[d-1][start]]++;
			deg[ind]++;
			
			adj[mp[d-1][start]].push_back(ind);
		}
	}
	cout<<n-1<<endl;
	dfs(root);
	return 0;
}
