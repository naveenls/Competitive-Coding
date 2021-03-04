#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	pair<int,int> temp[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		temp[i]={-arr[i],i};
	}
	
	sort(temp,temp+n);
	
	int m;
	cin>>m;
	
	int k,pos;
	
	vector<pair< pair<int,int> , int > > v(m);
	for(int i=0;i<m;i++)
	{
		cin>>k>>pos;
		
		v[i]={{k,pos},i};
	}
	sort(v.begin(),v.end());
	
	ordered_set o_set;
	
	int start=0;
	
	int ans[m];
	
	for(int i=0;i<m;i++)
	{
		while(o_set.size()<v[i].first.first)
		{
			o_set.insert(temp[start].second);
			start++;	
		}	
		int ind=*o_set.find_by_order(v[i].first.second-1);
		
		ans[v[i].second]=arr[ind];
	}
	
	for(int i=0;i<m;i++)
		cout<<ans[i]<<endl;
		
	return 0;
}
