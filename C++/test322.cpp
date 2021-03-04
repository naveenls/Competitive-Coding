#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;
vector<int> adj[maxN];

map<pair<int,int> , int > mp;
map<int , pair<int,int> > inv_mp;

long double count1[maxN];
long double count2[maxN];

int n;

long double dfs(int i,int p)
{
	long double count=1;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			long double temp=dfs(ch,i);
			
			int ind=mp[{min(i,ch),max(i,ch)}];
			count1[ind]=temp;
			count2[ind]=(long double)n-temp;
			
			count+=temp;
		}
	}
	return count;
}
int main()
{
	cin>>n;
	
	long double weight[n-1];
	
	int u,v;
	long double w;
	
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v>>w,u--,v--;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
		weight[i]=w;
		
		mp[{min(u,v),max(u,v)}]=i;
		inv_mp[i]={min(u,v),max(u,v)};
	}
	
	dfs(0,-1);
	
	long double ans=0;
	long double value[n-1];
	
	for(int i=0;i<n-1;i++)
	{
		value[i]=(count1[i]*count2[i]*(count1[i]+count2[i]-2))*weight[i];
		
		ans+=value[i];
	}
	
	long double denom=n;
	denom=denom*(denom-1)*(denom-2)/6;
	
	int q;
	cin>>q;
	
	int ind;
	for(int i=0;i<q;i++)
	{
		cin>>ind>>w,ind--;
		
		ans-=value[ind];
		value[ind]=(value[ind]/weight[ind])*w;
		weight[ind]=w;
		
		ans+=value[ind];
		
		cout<<fixed<<setprecision(10)<<ans/denom<<endl;
	}
	return 0;
}
