#include<bits/stdc++.h>
using namespace std;

vector<long long> need;
vector<long long> give;

bool check(long long ini)
{
	
	for(int i=0;i<need.size();i++)
	{
		if(give[i]==0)
		{
			if(ini<need[i])
			{
				return false;
			}
			ini-=need[i];
		}
		else
		{
			if(ini>=need[i])
			{
				ini+=give[i];
			}
		}
	}
	
	return ini>=1;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int x;
		cin>>x;
		
		int b;
		cin>>b;
		
		vector<pair<long long,long long> > dish(b);
		
		for(int i=0;i<b;i++)
		{
			cin>>dish[i].first>>dish[i].second;
		}
		
		int c;
		cin>>c;
		
		vector<pair<long long,pair<long long,long long> > > tribe(c);
		
		for(int i=0;i<c;i++)
		{
			cin>>tribe[i].first>>tribe[i].second.first>>tribe[i].second.second;
		}
		
		int i=0,j=0;
		
		need.clear();
		give.clear();
		
		while(i<b && j<c)
		{
			if(tribe[j].first<=dish[i].first)
			{
				need.push_back(tribe[j].second.first);
				give.push_back(tribe[j].second.second);
				j++;
			}
			else
			{
				need.push_back(dish[i].second);
				give.push_back(0);
				i++;
			}
		}
		
		while(j<c)
		{
			need.push_back(tribe[j].second.first);
			give.push_back(tribe[j].second.second);
			j++;
		}
		while(i<b)
		{
			need.push_back(dish[i].second);
			give.push_back(0);
			i++;
		}
		
		long long l=1,r=1e18;
		long long ans;
		
		while(l<=r)
		{
			long long mid=(l+r)>>1;
			
			if(check(mid))
			{
				ans=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
