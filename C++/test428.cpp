#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5+1;

vector<int> adj[maxN];

void dfs(int i,int p)
{
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			cout<<i<<' '<<ch<<endl;
			dfs(ch,i);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	
	int arr[n-1];
	int freq[n+1]={0};
	
	for(int i=0;i<n-1;i++)
	{
		cin>>arr[i];
		freq[arr[i]]++;
	}
	
	reverse(arr,arr+n-1);
		
	int val[n+1];

	priority_queue<pair<int,int> > pq;
	
	for(int i=1;i<=n;i++)
	{
		val[i]=i;
		if(freq[i]==0)
		{
			pq.push({-val[i],i});
		}
	}
	
	for(int i=0;i<n-1;i++)
	{
		if(!pq.size())
		{
			cout<<-1<<endl;
			return 0;
		}
		
		auto pr=pq.top();
		pq.pop();
				
		adj[pr.second].push_back(arr[i]);
		adj[arr[i]].push_back(pr.second);
		val[arr[i]]=max(val[arr[i]],val[pr.second]);
		
		freq[arr[i]]--;
		
		if(freq[arr[i]]==0)
		{
			pq.push({-val[arr[i]],arr[i]});
		}
	}

	int u=pq.top().second;
	
	cout<<u<<endl;
	
	dfs(u,0);
	
	return 0;
}
