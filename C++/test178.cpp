#include<bits/stdc++.h>
using namespace std;
const int maxM=1e5 + 10;
const int maxN=1e5+10;

int arr[maxN];
vector<pair<int,pair<int,int> > > v;

int find_par(int i,int par[])
{
	if(i==par[i])
		return i;
	
	par[i]=find_par(par[i],par);
	return par[i];
}
int main()
{
	long long n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b,a--,b--;
		v.push_back({min(arr[a],arr[b]),{a,b}});	
	}
	
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	long long sum=0;
	
	int par[n];
	int size[n];
	
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		size[i]=1;
	}
	
	for(int i=0;i<m;i++)
	{
		int val=v[i].first;
		auto pr=v[i].second;
		
		int a=find_par(pr.first,par);
		int b=find_par(pr.second,par);
		
		if(a!=b)
		{
			int sz1=size[a],sz2=size[b];
			
			if(sz1<sz2)
			{
				par[b]=a;
				size[a]=sz1+sz2;
			}
			else
			{
				par[a]=b;
				size[b]=sz1+sz2;
			}
			
			int t_size=sz1+sz2;
			
			sum+=((long long)t_size*(t_size-1) - (long long)sz1*(sz1-1) - (long long)sz2*(sz2-1))*(long long)val;
			//cout<<sum<<endl;
		}
	}
	cout<<fixed<<setprecision(10)<<(long double)sum/(n*(n-1))<<endl;
	return 0;
}
