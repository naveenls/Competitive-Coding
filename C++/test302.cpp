#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		vector<int> adj[n];
		
		long double a[n],b[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];	
		}
		long double ma=0;
		
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			
			a[i]/=b[i];
			
			ma=max(ma,a[i]);
		}
		
		int u,v_;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v_,u--,v_--;
			adj[u].push_back(v_);
			adj[v_].push_back(u);	
		}
		
		vector<int> max_len;
		
		bool col[n]={0};
		for(int i=0;i<n;i++)
		{
			if(col[i]==0 && a[i]==ma)
			{
				vector<int> v;
				
				queue<int> q;
				q.push(i);
				col[i]=1;
				v.push_back(i);
				
				while(!q.empty())
				{
					int ele=q.front();
					q.pop();
					
					for(auto ch:adj[ele])
					{
						if(col[ch]==0 && a[ch]==ma)
						{
							q.push(ch);
							col[ch]=1;
							v.push_back(ch);
						}
					}
				}
				
				if(max_len.size()<v.size())
				{
					max_len=v;
				}
			}
		}
		cout<<max_len.size()<<endl;
		for(auto ele:max_len)
			cout<<ele+1<<' ';
		cout<<endl;
	}
	return 0;
}
