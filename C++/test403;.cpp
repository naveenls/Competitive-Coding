#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5;

int arr[maxN];
vector<int> adj[maxN];
int ans[maxN];

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	memset(ans,-1,sizeof(ans));
	
	for(int i=0;i<n;i++)
	{
		if(i-arr[i]>=0)
		{
			if(arr[i]%2 != arr[i-arr[i]]%2)
			{
				ans[i]=1;
			}
			else
			{
				adj[i-arr[i]].push_back(i);
			}
		}
		
		if(i+arr[i]<=n-1)
		{
			if(arr[i]%2 != arr[i+arr[i]]%2)
			{
				ans[i]=1;
			}
			else
			{
				adj[i+arr[i]].push_back(i);
			}
		}
	}
	
	queue<int> q;
	
	
	for(int i=0;i<n;i++)
	{
		if(ans[i]!=-1)
			q.push(i);
	}
	
	while(!q.empty())
	{
		int ind=q.front();
		q.pop();
		
		for(auto ch:adj[ind])
		{
			if(ans[ch]==-1)
			{
				ans[ch]=ans[ind]+1;
				q.push(ch);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<' ';
	}
}
