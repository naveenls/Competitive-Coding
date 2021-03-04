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
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	ordered_set l_set,r_set;
	
	l_set.insert(arr[0]);
	for(int i=1;i<n;i++)
	{
		r_set.insert(arr[i]);
	}
	
	long long ans=0;
	
	for(int i=1;i<n-1;i++)
	{
		l_set.insert(arr[i]);
		
		long long l1=l_set.size()-l_set.order_of_key(arr[i])-1;
		long long l2=r_set.order_of_key(arr[i]);
		
		ans+=l1*l2;
		
		r_set.erase(arr[i]);
	}
	cout<<ans<<endl;
}
