#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5;

vector<int> adj[maxN];
int dist[maxN];

vector<pair<int,int> > v;

map<pair<int,int> ,int> mp;

vector<pair<int,int> > ans;

vector<vector<int> > f_ans;

int n,m,k;
int cnt=0;

void print_tree(int start)
{
	if(ans.size()==n-1)
	{
		vector<int> temp(m,0);
		
		for(auto ele:ans)
		{
			int ind=mp[{min(ele.first,ele.second),max(ele.first,ele.second)}];
			temp[ind]=1;
		}
		
		f_ans.push_back(temp);
		
		cnt++;
		if(cnt==k)
		{
			cout<<f_ans.size()<<endl;
			for(auto vec:f_ans)
			{
				for(auto ss:vec)
					cout<<ss;
				cout<<endl;
			}
			exit(0);
		}
		return;	
	}
	
	int ver=v[start].second;
	
	for(auto ch:adj[ver])
	{
		if(dist[ch]==dist[ver]-1)
		{
			ans.push_back({ch,ver});
			print_tree(start+1);
			ans.pop_back();
		}
	}
}
int main()
{
	cin>>n>>m>>k;
	
	int u,v_;
		
	for(int i=0;i<m;i++)
	{
		cin>>u>>v_,u--,v_--;
		
		mp[{min(u,v_),max(u,v_)}]=i;
		adj[u].push_back(v_);
		adj[v_].push_back(u);
	}
	
	memset(dist,-1,sizeof(dist));
	
	dist[0]=0;
	queue<int> q;
	q.push(0);
	
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		for(auto ch:adj[v])
		{
			if(dist[ch]==-1)
			{
				dist[ch]=dist[v]+1;
				q.push(ch);
			}
		}
	}
	
	for(int i=0;i<n;i++)
		v.push_back({dist[i],i});
	
	sort(v.begin(),v.end());
	/*
	for(auto ele:v)
	{
		cout<<ele.first<<' '<<ele.second<<endl;
	}*/
	print_tree(1);
	
	cout<<f_ans.size()<<endl;
	for(auto vec:f_ans)
	{
		for(auto ss:vec)
			cout<<ss;
		cout<<endl;
	}
	return 0;
}
