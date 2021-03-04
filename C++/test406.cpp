#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m,a,b;
		cin>>n>>m>>a>>b,a--,b--;
		
		set<int> adj[n];
		
		int u,v;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v,u--,v--;
			adj[u].insert(v);
			adj[v].insert(u);
		}
		
		queue<int> q;
		q.push(b);
		
		int col[n]={0};
		col[b]=1;
		
		while(!q.empty())
		{
			int ver=q.front();
			q.pop();
			
			for(auto ch:adj[ver])
			{
				if(ch!=a && col[ch]==0)
				{
					col[ch]=1;
					q.push(ch);
				}
			}
		}
		
		q.push(a);
		int col1[n]={0};
		col1[a]=1;
		
		while(!q.empty())
		{
			int ver=q.front();
			q.pop();
			
			for(auto ch:adj[ver])
			{
				if(ch!=b && col1[ch]==0)
				{
					col1[ch]=1;
					q.push(ch);
				}
			}
		}
		
		long long c1=0,c2=0;
		
		for(int i=0;i<n;i++)
		{
			if(i==a || i==b)
				continue;
				
			if(col1[i]==0 && col[i]==1)
				c1++;
			else if(col1[i]==1 && col[i]==0)
				c2++;
		}
		cout<<c1*c2<<endl;
	}
	return 0;
}
