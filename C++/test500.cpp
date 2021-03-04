#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;
vector<int> adj[maxN];
bool flag=0;

int p[maxN];
int h[maxN];

int x[maxN];
int y[maxN];

void reset(int n)
{
	for(int i=0;i<n;i++)
	{
		adj[i].clear();
		x[i]=y[i]=0;
	}
	flag=0;
}


int dfs(int i,int par)
{
	int num_ch=p[i];
	int s1=0;
	int s2=0;
		
	for(auto ch:adj[i])
	{
		if(ch!=par)
		{
			num_ch+=dfs(ch,i);
			s1+=x[ch];
			s2+=y[ch];
		}
	}
	
	int val1=(num_ch+h[i]);
	int val2=(num_ch-h[i]);
	
	if(val1%2 || val1<0 || val2<0)
	{
		//cout<<i+1<<' '<<val1<<' '<<val2<<endl;
		flag=1;
	}
	else
	{
		val1/=2;
		val2/=2;
		
		int a1=val1-s1;
		int a2=val2-s2;
		
		if(a1<0 || a2>p[i])
		{
			//cout<<i+1<<' '<<a1<<' '<<a2<<endl;
			flag=1;
		}
		
		x[i]=val1;
		y[i]=val2;
	}
	return num_ch;
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
			
		int m;
		cin>>m;
		
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>h[i];
		}
		
		int u,v;
		
		for(int i=0;i<n-1;i++)
		{
			cin>>u>>v,u--,v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		dfs(0,-1);
		
		if(flag)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
