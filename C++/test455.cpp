#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<pair<pair<int,int> ,int> > v;
	
	int l[n],r[n];
	for(int i=0;i<n;i++)
	{
		cin>>l[i]>>r[i];
		
		v.push_back({{r[i],1},i});
	}
	
	int m;
	cin>>m;
	
	int l1[m],r1[m];
	int k[m];
	
	for(int i=0;i<m;i++)
	{
		cin>>l1[i]>>r1[i]>>k[i];
		v.push_back({{r1[i],2},i});
	}
	
	sort(v.begin(),v.end());
	
	multimap<int,pair<int,int> > mp;
	
	int ans[n];
	
	for(int i=n+m-1;i>=0;i--)
	{
		int type=v[i].first.second;
		
		if(type==1)
		{
			while(mp.size() && -mp.begin()->first>v[i].first.first)
			{
				mp.erase(mp.begin()->first);
			}
			
			if(!mp.size())
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else
			{
				auto itr=mp.lower_bound(-l[v[i].second]);
				if(itr==mp.end())
				{
					cout<<"NO"<<endl;
					return 0;
				}
				
				ans[v[i].second]=(*itr).second.second;
				
				if(itr->second.first==1)
				{
					mp.erase(itr);
				}
				else
				{
					itr->second.first--;
				}
			}
		}
		else
		{
			mp.insert({-l1[v[i].second],{k[v[i].second],v[i].second}});
		}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]+1<<' ';
	}
	return 0;
}
