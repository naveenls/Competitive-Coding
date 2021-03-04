#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int> adj[n];
		int u,v;
		for(int i=0;i<n-1;i++)
		{
			cin>>u>>v,u--,v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		cout<<"? "<<n<<' ';
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<' ';
		}
		cout<<endl;
		
		int x,d;
		
		cin>>x>>d;
		x--;
		
		int dist[n];
		memset(dist,-1,sizeof(dist));
		dist[x]=0;
		
		queue<int> q;
		q.push(x);
		
		while(!q.empty())
		{
			int ind=q.front();
			q.pop();
			
			for(auto ch:adj[ind])
			{
				if(dist[ch]==-1)
				{
					dist[ch]=dist[ind]+1;
					q.push(ch);
				}
			}
		}
		
		map<int,vector<int> > mp;
		
		for(int i=0;i<n;i++)
		{
			mp[dist[i]].push_back(i);
		}
		int l=d-d/2,r=n;
		
		int ans_ind;
		
		int index;
		int distance;
		
		while(l<=r)
		{
			int mid=(l+r)/2;
			
			if(mp.find(mid)==mp.end())
			{
				r=mid-1;
				continue;
			}
			
			cout<<"? "<<mp[mid].size()<<' ';
			for(auto ele:mp[mid])
			{
				cout<<ele+1<<' ';
			}
			cout<<endl;
			
			cin>>index>>distance,index--;
			
			if(distance==d)
			{
				ans_ind=index;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		
		int ans_ind1;
		
		memset(dist,-1,sizeof(dist));
		dist[ans_ind]=0;
		
		q.push(ans_ind);
		
		while(!q.empty())
		{
			int ind=q.front();
			q.pop();
			
			for(auto ch:adj[ind])
			{
				if(dist[ch]==-1)
				{
					dist[ch]=dist[ind]+1;
					q.push(ch);
				}
			}
		}
		
		vector<int> v1;
		for(int i=0;i<n;i++)
		{
			if(dist[i]==d)
			{
				v1.push_back(i+1);
			}
		}
		
		cout<<"? "<<v1.size()<<' ';
		for(auto ele:v1)
		{
			cout<<ele<<' ';
		}
		cout<<endl;
		
		cin>>ans_ind1>>d;
		
		cout<<"! "<<ans_ind+1<<' '<<ans_ind1<<endl;
		string s;
		cin>>s;
	}
	return 0;
}
