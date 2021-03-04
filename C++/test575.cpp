#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;
string s;

vector<int> adj[maxN];

long long sum=0;

pair<int,int> dfs(int i,int p,int flag,int depth)
{
	int type1=0;
	int type2=0;
	
	if(flag != s[i]-'0')
	{
		if(flag==1)
		{
			type1++;
		}
		else
		{
			type2++;
		}
	}	
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			pair<int,int> temp=dfs(ch,i,1-flag,depth+1);
			
			sum+=temp.first;
			
			if(temp.second==1)
			{
				type1+=temp.first;
			}
			else
			{
				type2+=temp.first;
			}
		}
	}
	
	if(type1 > type2)
	{
		return {type1-type2,1};
	}
	else
	{
		return {type2-type1,0};
	}
}

void reset(int n)
{
	for(int i=0;i<n;i++)
	{
		adj[i].clear();
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		reset(n);
		
		int u,v;
		for(int i=0;i<n-1;i++)
		{
			cin>>u>>v,u--,v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		cin>>s;
		
		long long mi=1e18;
		
		sum=0;
		pair<int,int> pr=dfs(0,-1,0,0);
		
		if(pr.first==0)
		{
			mi=min(mi,sum);
		}
		
		sum=0;
		pr=dfs(0,-1,1,0);
		
		if(pr.first==0)
		{
			mi=min(mi,sum);
		}
		
		if(mi==1e18)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<mi<<endl;
		}
	}
	return 0;
}
