#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	map<int,int> mp;
	int x;
	
	queue<int> q;
	
	for(int i=0;i<n;i++)
	{
		cin>>x;
		mp[x]=0;
		q.push(x);
	}
	
	vector<int> ans;
	
	while(!q.empty() && ans.size()<m)
	{
		int v=q.front();
		q.pop();
		
		if(mp.find(v+1)==mp.end())
		{
			mp[v+1]=mp[v]+1;
			q.push(v+1);
			
			ans.push_back(v+1);
		}
		if(mp.find(v-1)==mp.end())
		{
			mp[v-1]=mp[v]+1;
			q.push(v-1);
			
			ans.push_back(v-1);
		}
	}
	
	long long sum=0;
	
	for(int i=0;i<m;i++)
	{
		sum+=mp[ans[i]];
	}
	
	cout<<sum<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
