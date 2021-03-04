#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;
long long arr[maxN];
long long denom[maxN];
bool flag;

vector<int> adj[maxN];

map<long long,int> mp;

void factorize(long long a)
{
	if(a==0 || a==1)
		return;
	
	int cnt=0;
	
	while(a%2==0)
	{
		a/=2;
		cnt++;	
	}
	
	mp[2]=max(mp[2],cnt);
	
	for(long long i=3;i*i<=a;i++)
	{
		if(a%i==0)
		{
			cnt=0;
			while(a%i==0)
			{
				a/=i;
				cnt++;
			}
			mp[i]=max(mp[i],cnt);
		}
	}
	
	if(a>1)
	{
		mp[a]=max(mp[a],1);
	}
} 
void dfs(int v,int p,int root,long long dd)
{
	if(v==root)
	{
		denom[v]=1;
		for(auto ch:adj[v])
		{
			dfs(ch,v,root,1LL);
		}
	}
	else
	{
		denom[v]=dd;
		
		if(dd>2*1e8)
		{
			flag=1;
			dd=1;
		}
		
		long long next=dd*((long long)adj[v].size()-1LL);
		
		for(auto ch:adj[v])
		{
			if(ch!=p)
			{
				dfs(ch,v,root,next);
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b,a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(0,-1,0,1);
	
	vector<long long> v;
	
	for(int i=0;i<n;i++)
	{
		if(adj[i].size()<=1 && i!=0)
			v.push_back(denom[i]);
	}
	
	long long mi=1e18;
	long long lcm=1;
	if(flag)
	{
		mi=0;
	}
	else
	{
		for(auto ele:v)
		{
			factorize(ele);
		}
		
		for(auto itr=mp.begin();itr!=mp.end();++itr)
		{
			int temp=itr->second;
			while(temp--)
			{
				lcm*=itr->first;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			if(adj[i].size()<=1 && i!=0)
				mi=min(mi,arr[i]*denom[i]);
		}
	}
	
	mi=(mi/lcm)*lcm;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(adj[i].size()<=1 && i!=0)
			ans+=(arr[i] - mi/denom[i]);
	}
	
	cout<<ans<<endl;
	return 0;
}
