#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

ordered_set o_set;
 
void find_fact(int arr[],int sum[],int n)
{
	for(int i=0;i<n;i++)
		o_set.insert(i);
		
	for(int i=0;i<n;i++)
	{
		sum[n-i-1]+=o_set.order_of_key(arr[i]);
		o_set.erase(arr[i]);
	}
}
int main()
{
	int n;
	cin>>n;
	
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	
	int s[n+1]={0};
	find_fact(a,s,n);
	find_fact(b,s,n);
	
	for(int i=0;i<n;i++)
	{
		s[i+1]+=s[i]/(i+1);
		s[i]%=(i+1);
	}
	o_set.clear();
	
	for(int i=0;i<n;i++)
	{
		o_set.insert(i);
	}
	for(int i=0;i<n;i++)
	{
		int ele=*o_set.find_by_order(s[n-i-1]);
		cout<<ele<<' ';
		o_set.erase(ele);
	}
	return 0;
}
