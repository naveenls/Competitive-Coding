#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,m;
		cin>>n>>x>>m;
		
		vector<pair<int,int> > v;
		v.push_back({x,x});
		
		int u,v_;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v_;
			
			bool flag=0;
			for(auto ele:v)
			{
				if(v_<ele.first || u>ele.second)
				{
					continue;
				}
				else
				{
					v.push_back({u,v_});
					break;
				}
			}
		}
		
		sort(v.begin(),v.end());
		/*
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i].first<<' '<<v[i].second<<endl;
		}*/
		int ans=0;
		
		for(int i=0;i<v.size();)
		{
			int r_end=v[i].second;
			
			int j=i+1;
			
			for(;j<v.size();j++)
			{
				if(v[j].first>r_end)
				{
					break;
				}
				else
				{
					r_end=max(r_end,v[j].second);
				}
			}
			ans+=(r_end-v[i].first+1);
			i=j;
		}
		cout<<ans<<endl;
	}
	return 0;
}
