#include<bits/stdc++.h>
using namespace std;

const int maxN = 5e5+10;
set<int> adj[maxN];

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		set<int> notFound;
		for(int i=0;i<n;i++)
		{
			notFound.insert(i);
			adj[i].clear();
		}
		
		int u,v;
		while(m--)
		{
			cin>>u>>v;
			u--,v--;
			
			adj[u].insert(v);
			adj[v].insert(u);
		}
				
		int cnt = 0;
		
		int ans[n];
		memset(ans,-1,sizeof(ans));
		
		for(int i=0;i<n;i++)
		{
			if(notFound.find(i) != notFound.end())
			{
				vector<int> friends;
				queue<int> q;
				
				q.push(i);
				notFound.erase(i);
				
				while(q.size())
				{
					int u = q.front();
					friends.push_back(u);
					
					q.pop();
					
					vector<int> toDel;
					for(auto ele:notFound)
					{
						if(adj[u].find(ele) == adj[u].end()){
							toDel.push_back(ele);
							q.push(ele);
						}
					}
					
					for(auto ele:toDel)
						notFound.erase(ele);
				}
				
				bool flag = true;
				for(auto j:friends)
				{
					if(n-adj[j].size() != friends.size())
						flag = false;
				}
				
				if(flag)
				{
					cnt++;
					if(ans[0] == -1)
					{
						memset(ans,0,sizeof(ans));
						
						for(auto j:friends)
							ans[j] = 1;
					}
				}
			}
		}
		
		cout<<cnt<<endl;
		if(!cnt)
			memset(ans,0,sizeof(ans));
		
		for(int i=0;i<n;i++)
			cout<<ans[i];
		cout<<endl;
	}
	
	return 0;
}
