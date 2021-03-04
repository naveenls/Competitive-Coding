#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update> 

int main()
{
	int n,m;
	cin>>n>>m;
	
	int y[n],l[n],r[n];
	
	long long ans=1;
	
	int end=1e6;
	
	vector<pair<int,pair<int,int> > > points;
	
	for(int i=0;i<n;i++)
	{
		cin>>y[i]>>l[i]>>r[i];
		
		if(l[i]==0 && r[i]==end)
		{
			ans++;
		}
		
		points.push_back({y[i],{1,i}});
	}
	
	int x[m],l1[m],r1[m];
	
	for(int i=0;i<m;i++)
	{
		cin>>x[i]>>l1[i]>>r1[i];
		
		if(l1[i]==0 && r1[i]==end)
		{
			ans++;
		}
		
		points.push_back({l1[i],{0,i}});
		points.push_back({r1[i],{2,i}});
	}
	
	sort(points.begin(),points.end());
	
	ordered_set o_set;
		
	for(int i=0;i<points.size();i++)
	{
		int h=points[i].first;
		
		int type=points[i].second.first;
		int j=points[i].second.second;
				
		if(type==0)
		{
			o_set.insert(x[j]);
			
		//	cout<<"+ "<<x[j]<<endl;
			
		}
		else if(type==1)
		{
			if(l[j]==0)
			{
				double d=r[j];
				d+=0.1;
				
				o_set.insert(d);
				
				//cout<<d<<' '<<o_set.order_of_key(d)<<endl;
				
				ans+=o_set.order_of_key(d);
				
				o_set.erase(d);
			}
			else
			{
				double d=l[j];
				d-=0.1;
				
				o_set.insert(d);
				
				//cout<<d<<' '<<o_set.order_of_key(d)<<endl;
				
				ans+=(o_set.size() - o_set.order_of_key(d) - 1);
				
				o_set.erase(d);
			}
		}
		else
		{
			o_set.erase(x[j]);
			
			//cout<<"- "<<x[j]<<endl;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
