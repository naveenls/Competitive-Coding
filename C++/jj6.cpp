#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		vector<int> adj[n];
		
		int u,v;
		for(int i=0;i<n-1;i++)
		{
			cin>>u>>v;
			u--,v--;
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		if(n==2 && k==1)
		{
			cout<<1<<endl;
			continue;
		}
		
		int cnt[n]={0};
		for(int i=0;i<n;i++)
		{
			if(adj[i].size()==1)
			{
				cnt[adj[i][0]]++;
			}
		}
		
		queue<int> q;
		
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(cnt[i])
				q.push(i);	
		}
		
		while(!q.empty())
		{
			int v=q.front();
			q.pop();
			
			ans+=(cnt[v]/k)*k;
			
			cnt[v]%=k;
			
			if(cnt[v]==0)
			{
				int u=-1;
				
				for(auto ch:adj[v])
				{
					if(adj[ch].size()>1)
					{
						u=ch;
						break;
					}
				}
				
				adj[v].clear();
				
				if(u!=-1)
				{
					cnt[u]++;
					q.push(u);
				}
			}	
		}
		cout<<ans/k<<endl;
	}
	return 0;
}
