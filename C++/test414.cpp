#include<bits/stdc++.h>
using namespace std;

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
	
	vector<pair<int,int> > v(n);
	int par[n];
	
	int l,r;
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		cin>>l>>r;
		v[i]={r,l};
	}
	sort(v.begin(),v.end());
	
	map<int,int> mp;
	
	int num_comp=n;
	
	for(int i=n-1;i>=0;i--)
	{
		auto itr=mp.lower_bound(v[i].second);
		
		while(itr!=mp.end() && itr->first<v[i].first)
		{
			int a=find_par(i,par);
			int b=find_par(itr->second,par);
			
			if(a==b)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else
			{
				num_comp--;
				par[b]=a;
			}
			++itr;
		}
		mp[v[i].second]=i;
	}
	
	if(num_comp==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
