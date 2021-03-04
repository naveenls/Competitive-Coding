#include<bits/stdc++.h>
using namespace std;

int find_par(int a,int par[])
{
	if(a==par[a])
		return a;
	
	par[a]=find_par(par[a],par);
	return par[a];
}

int main()
{
	int n,m,p,q;
	cin>>n>>m>>p>>q;
	
	int par[n];
	int size[n];
	long long cost[n];
	
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		size[i]=1;
		cost[i]=0;
	}
	int u,v;
	long long w;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		u--,v--;
		cin>>w;
		
		int a=find_par(u,par);
		int b=find_par(v,par);
		
		if(a==b)
		{
			cost[a]+=w;
		}
		else
		{
			if(size[a]<size[b])
			{
				size[a]+=size[b];
				par[b]=a;
				cost[a]+=(cost[b]+w);
			}
			else
			{
				size[b]+=size[a];
				par[a]=b;
				cost[b]+=(cost[a]+w);
			}
		}
	}
	
	vector<pair<long long,int> > comps;
	
	for(int i=0;i<n;i++)
	{
		if(par[i]==i)
		{
			comps.push_back({-cost[i],i});
		}
	}
	
	if(comps.size()<q)
	{
		cout<<"NO"<<endl;
		//cout<<"hi"<<endl;
		return 0;
	}
	else if(q==n && p)
	{
		cout<<"NO"<<endl;
		//cout<<"hi"<<endl;
		return 0;
	}
		
	make_heap(comps.begin(),comps.end());
	
	vector<pair<int,int> > ans;
	
	
	while(comps.size()>q && p)
	{
		auto p1=comps.front();
		pop_heap(comps.begin(), comps.end());
		comps.pop_back();
		
		auto p2=comps.front();
		pop_heap(comps.begin(), comps.end());
		comps.pop_back();
		
		long long temp=min((long long)1e9,cost[p1.second]+cost[p2.second]+1);
		
		int a=p1.second,b=p2.second;
		
		ans.push_back({a,b});
		
		if(size[a]<size[b])
		{
			size[a]+=size[b];
			par[b]=a;
			cost[a]+=(cost[b]+temp);
			comps.push_back({-cost[a],a});
		}
		else
		{
			size[b]+=size[a];
			par[a]=b;
			cost[b]+=(cost[a]+temp);
			comps.push_back({-cost[b],b});
		}
		push_heap(comps.begin(), comps.end());
		
		p--;
	}
	
	if(comps.size()>q)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(auto ele:ans)
	{
		cout<<ele.first+1<<' '<<ele.second+1<<endl;
	}
	int a1,a2;
	for(int i=0;i<n;i++)
	{
		if(i!=find_par(i,par))
		{
			a1=i;
			a2=find_par(i,par);
		}
	}
	while(p)
	{
		cout<<a1+1<<' '<<a2+1<<endl;
		p--;
	}
	return 0;
}
