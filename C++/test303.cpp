#include<bits/stdc++.h>
using namespace std;

long long find_sum(int val,vector<int> &v)
{
	long long ans=0;
	for(auto ele:v)
	{
		ans+= (long long)abs(val-ele);
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		long long c;
		cin>>c;
		
		int x[n],y[n];
		
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];
			
		map<int,set<int> > mp;
		for(int i=0;i<n;i++)
		{
			mp[x[i]-y[i]].insert(i);
		}
		
		int ans=0;
		long long count=0;
		
		for(auto ele:mp)
		{
			map<int,vector<int> > points;
			
			for(auto ind:ele.second)
			{
				points[(x[ind]%c+c)%c].push_back(x[ind]);
			}
			
			ans+=points.size();
			
			for(auto point:points)
			{
				sort(point.second.begin(),point.second.end());
				
				int num=point.second.size();
				if(num%2)
				{
					int val=point.second[num/2];
					
					long long temp=find_sum(val,point.second);
					
					count += temp/c;
				}
				else
				{
					int val1=point.second[num/2];
					int val2=point.second[num/2-1];
					
					long long temp=min(find_sum(val1,point.second),find_sum(val2,point.second));
					
					count += temp/c;
				}
			}
		}
		cout<<ans<<' '<<count<<endl;
	}
	return 0;
}
