#include<bits/stdc++.h>
using namespace std;

const int maxN=1000;
vector<int> adj[maxN];

int arr[maxN];
int temp[maxN];
bool ok[maxN]={0};

bool vis[maxN];
int child[maxN];

bool dfs(int i,int val)
{
	if(!vis[i])
	{
		vis[i]=1;
		
		if(val==temp[i] && !ok[i])
			return true;
			
		bool flag;
		
		for(auto ch:adj[i])
		{
			flag=dfs(ch,val);
			if(flag)
			{
				child[i]=ch;
				return true;	
			}	
		}
		return false;
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		temp[i]=arr[i];
	}
	
	sort(temp,temp+n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				adj[i].push_back(j);
				adj[j].push_bakc(i);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=temp[i])
		{
			vector<int> path;
			vector<pair<int,int> change;
			
			memset(vis,0,sizeof(vis));
			
			if(!dfs(i,arr[i]))
			{
				cout<<-1<<endl;
				return 0;
			}
			
			int start=i;
			while(temp[start]!=arr[i])
			{
				path.push_back(start);
				if(ok[child[start]])
				{
					change.push_back({child[start],start});
				}
				start=child[start];
			}
		}
		else
		{
			ok[i]=1;
		}
	}
	return 0;
}
