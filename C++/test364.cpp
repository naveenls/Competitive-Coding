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
	
	map<int,int> mp;
	ordered_set o_set;
	
	int m,f;
	
	for(int i=0;i<n;i++)
	{
		cin>>m>>f;
			
		mp[m]=f;	
		o_set.insert(f);
	}
	
	long long ans=0;
	
	for(auto ele:mp)
	{
		ans+=o_set.order_of_key(ele.second);
		
		o_set.erase(ele.second);
	}
	cout<<ans<<endl;
}
