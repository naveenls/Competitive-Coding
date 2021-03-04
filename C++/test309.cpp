#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<pair<int,pair<int,int> > > v(m);
	
	for(int i=0;i<m;i++)
	{
		cin>>v[i].first;
		cin>>v[i].second.first;
		v[i].second.first*=-1;
		
		v[i].second.second=i;
	}
	
	sort(v.begin(),v.end());
	
	int cnt=1;
	int last=1;
	
	int deg[n+1]={0};
	
	vector<pair<int,int> > ans(m);
	
	for(int i=0;i<m;i++)
	{
		if(v[i].second.first)
		{
			ans[v[i].second.second]={cnt,cnt+1};
			cnt++;
		}
		else
		{
			while(deg[last]>=last-2)
			{
				last++;
				if(last>cnt)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
			ans[v[i].second.second]={deg[last]+1,last};
			deg[last]++;
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	
	return 0;
}
