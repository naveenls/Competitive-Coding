#include<bits/stdc++.h>
using namespace std;

long long distance(pair<long long,long long> a,pair<long long,long long> b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int main()
{
	int n;
	cin>>n;
	
	long long x[n],y[n];
	
	map<long long,vector<int> > mp;
	
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		
		mp[max(x[i],y[i])].push_back(i);
	}
	
	long long DP[mp.size()][2];
	
	pair<long long,long long> t_l[mp.size()];
	pair<long long,long long> b_r[mp.size()];
	
	long long dist[mp.size()]={0};
	
	int i=0;
	for(auto ele:mp)
	{
		t_l[i]={ele.first+1,ele.first+1};
		b_r[i]={ele.first+1,ele.first+1};
				
		for(auto ind:ele.second)
		{
			if(y[ind]==ele.first)
			{
				t_l[i].first=min(t_l[i].first,x[ind]);
				t_l[i].second=ele.first;
			}
			
			if(x[ind]==ele.first)
			{
				b_r[i].second=min(b_r[i].second,y[ind]);
				b_r[i].first=ele.first;
			}
		}
		
		if(t_l[i].first==ele.first+1)
		{
			t_l[i].first=ele.first;
			t_l[i].second=0;
			
			for(auto ind:ele.second)
			{
				t_l[i].second=max(t_l[i].second,y[ind]);
			}
		}
		if(b_r[i].first==ele.first+1)
		{
			b_r[i].first=0;
			b_r[i].second=ele.first;
			
			for(auto ind:ele.second)
			{
				b_r[i].first=max(b_r[i].first,x[ind]);
			}
		}
		
		dist[i]=abs(b_r[i].first-t_l[i].first)+abs(b_r[i].second-t_l[i].second);
		i++;
	}

	DP[0][0]=dist[0]+t_l[0].first+t_l[0].second;
	DP[0][1]=dist[0]+b_r[0].first+b_r[0].second;
	
	for(int i=1;i<mp.size();i++)
	{
		DP[i][0]=dist[i]+min(DP[i-1][1] + distance(t_l[i],t_l[i-1]), DP[i-1][0] + distance(t_l[i],b_r[i-1]));
		DP[i][1]=dist[i]+min(DP[i-1][1] + distance(b_r[i],t_l[i-1]), DP[i-1][0] + distance(b_r[i],b_r[i-1]));
	}
	
	cout<<min(DP[mp.size()-1][0],DP[mp.size()-1][1]);
	return 0;
}
