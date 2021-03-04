#include<bits/stdc++.h>
using namespace std;

multiset<pair<pair<long long,int>,long long> > ms;

int dfs(int i,int p,vector<vector<pair<int,pair<long long,int> > > > &adj)
{
	int cnt=0;
	
	if(adj[i].size()==1 && adj[i][0].first==p)
	{
		return 1;
	}
	
	for(auto ch:adj[i])
	{
		if(ch.first!=p)
		{
			int temp=dfs(ch.first,i,adj);
			
			ms.insert({ch.second,temp});
			
			cnt+=temp;
		}
	}
	
	return cnt;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		long long s;
		cin>>s;
		
		vector<vector<pair<int,pair<long long,int> > > > adj(n);
		
		int a,b,c;
		long long w;
		for(int i=0;i<n-1;i++)
		{
			cin>>a>>b>>w>>c;
			a--,b--;
			
			adj[a].push_back({b,{w,c}});
			adj[b].push_back({a,{w,c}});
		}
		
		vector<int> sz(n);
		
		ms.clear();
		dfs(0,-1,adj);
		
		priority_queue<pair<long long,pair<long long,int> > > pq;
		priority_queue<pair<long long,pair<long long,int> > > pq1;
		
		long long t_sum=0;
		long long t_sum1=0;
		
		for(auto ele:ms)
		{
			if(ele.first.second==1)
			{
				t_sum+=ele.first.first*ele.second;
				pq.push({((ele.first.first+1)/2)*ele.second,{ele.first.first/2,ele.second}});
			}
			else
			{
				t_sum1+=ele.first.first*ele.second;
				pq1.push({((ele.first.first+1)/2)*ele.second,{ele.first.first/2,ele.second}});
			}
			
		}
		
		vector<long long> v,v1;
		
		v.push_back(t_sum);
		v1.push_back(t_sum1);
		
		while(t_sum)
		{
			auto pr=pq.top();
			pq.pop();
			
			t_sum-=pr.first;
			
			v.push_back(t_sum);
			
			//cout<<t_sum<<endl;
			long long val=pr.second.first;
			long long x=pr.second.second;
			
			pq.push({((val+1)/2)*x,{val/2,x}});
		}
		
		while(t_sum1)
		{
			auto pr=pq1.top();
			pq1.pop();
			
			t_sum1-=pr.first;
			
			v1.push_back(t_sum1);
			//cout<<t_sum1<<endl;
			
			long long val=pr.second.first;
			long long x=pr.second.second;
			
			pq1.push({((val+1)/2)*x,{val/2,x}});			
		}
		
	
		int i=0,j=v1.size()-1;
		
		int mi=1e9;
		
		for(int i=0;i<v.size();i++)
		{
			if(v[i]<=s)
			{
				while(j>=0 && v[i]+v1[j]<=s)
				{
					j--;
				}
				
				j++;
				if(v1[j]+v[i]<=s)
					mi=min(mi,i+2*j);
			}
		}
		
		cout<<mi<<endl;
	}
}
