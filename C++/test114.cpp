#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxN=1e5;
vector<int> adj[maxN];

int main()
{
	cin>>n>>m;
	
	int a,b;
	int color[n];
	vector<int> col[maxN];
	
	for(int i=0;i<n;i++)
	{
		cin>>color[i];
		color[i]--;
		col[color[i]].push_back(i);
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int mx=0;
	int ind=-1;
	
	for(int i=0;i<maxN;i++)
	{
		if(col[i].size())
		{
			set<int> ss;
			ss.insert(i);
			for(auto ele:col[i])
			{
				for(auto nei:adj[ele])
				{
					ss.insert(color[nei]);
				}
			}
	
			if(ss.size()>mx)
			{
				mx=ss.size();
				ind=i+1;
			}
		}
	}
	cout<<ind<<endl;
	return 0;
}
