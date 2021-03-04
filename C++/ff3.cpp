#include<bits/stdc++.h>
using namespace std;

const int maxN=1010;

vector<int> adj[maxN];
int num_child[maxN];

int dfs(int i,int p,int root)
{
	if(i==root)
	{
		vector<int> v;
		
		for(auto ch:adj[i])
		{
			v.push_back(dfs(ch,i,root));
		}
		if(v.size()<=1)
		{
			return 0;
		}
		else
		{
			int eve=0;
			int odd=0;
			for(auto ele:v)
			{
				if(ele%2==0)
				{
					eve++;
				}
				else
					odd++;
			}
			if(odd%2)
			{
				return 0;
			}
			else
				return 1;
		}
	}
	else
	{
		int num_ch=0;
		for(auto ch:adj[i])
		{
			if(ch!=p)
			{
				num_ch+=dfs(ch,i,root);	
			}
		}
		return num_ch+1;
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		for(int i=0;i<n;i++)
			adj[i].clear();
			
		int a,b;
		
		
		for(int i=0;i<n-1;i++)
		{
			cin>>a>>b;
			a--,b--;
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		x--;
		if(dfs(x,-1,x))
		{
			cout<<"Ashish"<<endl;
		}
		else
			cout<<"Ayush"<<endl;
	}
	return 0;
}
