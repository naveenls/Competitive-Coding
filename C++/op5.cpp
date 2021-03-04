#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		int inD[n]={0};
		int outD[n]={0};
		
		set<int> adj[n];
		set<int> prev[n];
		
		int u,v;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			u--,v--;
			
			if(adj[u].find(v)==adj[u].end())
			{
				adj[u].insert(v);
				prev[v].insert(u);
							
				inD[v]++;
				outD[u]++;	
			}
		}
		set<int> ans;
		ans.insert(0);
		
		bool fl[n]={0};
		
		for(int i=1;i<n;i++)
		{
			bool flag=0;
			for(auto j:prev[i])
			{
				if(inD[j] && !fl[j])
				{
					flag=1;
					break;
				}
			}
			if(flag)
			{
				for(auto j:adj[i])
				{
					inD[j]--;
				}
				fl[i]=1;
			}
			else
			{
				ans.insert(i);
			}
		}
		cout<<n-ans.size()<<endl;
		for(int i=0;i<n;i++)
		{
			if(ans.find(i)==ans.end())
			{
				cout<<i+1<<' ';
			}
		}
		cout<<endl;
	}
	
	return 0;
}
