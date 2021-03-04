#include <bits/stdc++.h> 
using namespace std; 
  
const int maxN=1e5+1;

vector<int> adj[maxN];

int maxDown[maxN];
int maxUp[maxN];

int max1[maxN];
int max2[maxN];

bool mark[maxN]={0};

void dfs(int i,int p)
{
	maxDown[i]=-1e9;
	
	if(mark[i])
		maxDown[i]=0;
	
	vector<int> mdown;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			dfs(ch,i);
			maxDown[i]=max(maxDown[i],maxDown[ch]+1);
			
			mdown.push_back(maxDown[ch]);
		}
	}
	sort(mdown.begin(),mdown.end(),greater<int> ());
	
	if(mdown.size()>1)
	{
		max1[i]=mdown[0];
		max2[i]=mdown[1];
	}
	else if(mdown.size()==1)
	{
		max1[i]=mdown[0];
		max2[i]=-1e9;
	}
	else
	{
		max1[i]=-1e9;
		max2[i]=-1e9;
	}
}

void dfs1(int i,int p)
{
	if(p==-1)
	{
		maxUp[i]=-1e9;
		
		for(auto ch:adj[i])
		{
			if(ch!=p)
				dfs1(ch,i);
		}
	}
	else
	{
		maxUp[i]=-1e9;
	
		if(maxDown[i]==max1[p])
		{
			maxUp[i]=max2[p]+2;
		}
		else
		{
			maxUp[i]=max1[p]+2;
		}
		
		if(mark[p])
		{
			maxUp[i]=max(maxUp[i],1);
		}
		maxUp[i]=max(maxUp[i],maxUp[p]+1);
		
		for(auto ch:adj[i])
		{
			if(ch!=p)
				dfs1(ch,i);
		}
	}
}
int main() 
{ 
    int n,m,k;
    cin>>n>>m>>k;
    
    int a,b;
    for(int i=0;i<m;i++)
    {
    	cin>>a,a--;
    	mark[a]=1;
	}
	
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b,a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(0,-1);
	dfs1(0,-1);
	
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		//cout<<maxDown[i]<<' '<<maxUp[i]<<endl;
		if(max(maxDown[i],maxUp[i])<=k)
			cnt++;
	}
	cout<<cnt<<endl;
    return 0; 
} 
