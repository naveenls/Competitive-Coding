#include<bits/stdc++.h>
using namespace std;

int find_par(int i,int par[])
{
	if(par[i]==-1)
		return -1;
		
	if(i==par[i])
		return i;
	par[i]=find_par(par[i],par);
	return par[i];
}

vector<pair<int,int> > v,v1;
long long ans=0;

void find_ans(int n,vector<pair<int,int> > &v)
{
	int par[n];
		
	for(int i=0;i<n;i++)
	{
		par[i]=i;
	}
	
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++)
	{
		if(v[i].second>=0)
		{
			int p=find_par(v[i].second,par);
		
			if(p!=-1)
			{
				ans+=v[i].first;
				par[p]=p-1;
			}	
		}
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		v.clear();
		v1.clear();
		
		ans=0;
		
		int n;
		cin>>n;
				
		int k[n];
		int r[n];
		int l[n];
				
		for(int i=0;i<n;i++)
		{
			cin>>k[i]>>l[i]>>r[i];
			k[i]--;
			
			ans+=min(l[i],r[i]);
			
			if(l[i]>=r[i])
			{
				v.push_back({l[i]-r[i],k[i]});
			}
			else
			{
				v1.push_back({r[i]-l[i],n-k[i]-2});
			}
		}
		
		find_ans(n,v);
		find_ans(n,v1);
		
		cout<<ans<<endl;
	}
}
