#include<bits/stdc++.h>
using namespace std;

long long find_lca(long long u,long long v)
{
	set<long long> p;
	
	while(u)
	{
		p.insert(u);
		u/=2;
	}
		
	while(v)
	{
		if(p.find(v)!=p.end())
		{
			return v;
		}
		v/=2;
	}
}
int main()
{
	map<pair<long long,long long> ,long long> mp;
	
	int q;
	cin>>q;
	
	int type;
	long long u,v;
	
	long long w;
	while(q--)
	{
		cin>>type>>u>>v;
		
		if(type==1)
		{
			cin>>w;
			
			long long lca=find_lca(u,v);
			
			while(v!=lca)
			{
				mp[{v/2,v}]+=w;
				v/=2;
			}
			
			while(u!=lca)
			{
				mp[{u/2,u}]+=w;
				u/=2;
			}
		}
		else
		{
			long long lca=find_lca(u,v);
			
			long long ans=0;
			
			while(v!=lca)
			{
				ans+=mp[{v/2,v}];
				v/=2;
			}
			
			while(u!=lca)
			{
				ans+=mp[{u/2,u}];
				u/=2;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
