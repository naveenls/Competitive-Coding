#include<bits/stdc++.h>
using namespace std;

long long calc_dist(long long x,long long y,long long x1,long long y1,long long k1,long long k2)
{
    return (k1+k2)*(abs(x-x1)+abs(y-y1));
}
    
int find_par(int i,int par[])
{
	if(i==par[i])
		return i;
		
	par[i]=find_par(par[i],par);
	
	return par[i];
}
int main()
{
	int n;
	cin>>n;
	
	long long x[n],y[n];
	
	for(int i=0;i<n;i++)
    	cin>>x[i]>>y[i];

    long long c[n],k[n];
	
	int par[n];
	int mi[n];
	
	long long cost=0;
	
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        par[i]=i;
        mi[i]=i;

        cost+=c[i];
    }
    
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
    }
    vector<pair<long long,pair<int,int> > > v;
    
    vector<pair<int,int> > e;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            long long dist=calc_dist(x[i],y[i],x[j],y[j],k[i],k[j]);
            v.push_back({dist,{i,j}});
        }
    }

	sort(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++)
	{
		long long weight=v[i].first;
		
		int a1=v[i].second.first;
		int b1=v[i].second.second;
		
		int a=find_par(a1,par);
		int b=find_par(b1,par);
		
		if(a!=b)
		{
			long long val1=c[mi[a]];
			long long val2=c[mi[b]];
			
			if(min(val1,val2)+weight<val1+val2)
			{
				cost-=(val1+val2 - min(val1,val2) - weight);
				
				par[b]=a;
				
				e.push_back({a1,b1});
				
				if(val1>val2)
				{
					mi[a]=mi[b];
				}
			}
		}
	}
	
	vector<int> ver;
	for(int i=0;i<n;i++)
	{
		if(par[i]==i)
			ver.push_back(mi[i]);
	}
	
	cout<<cost<<endl;
	cout<<ver.size()<<endl;
	for(auto ele:ver)
	{
		cout<<ele+1<<' ';
	}
	cout<<endl;
	
	cout<<e.size()<<endl;
	for(auto ele:e)
	{
		cout<<ele.first+1<<' '<<ele.second+1<<endl;
	}
	return 0;
}
