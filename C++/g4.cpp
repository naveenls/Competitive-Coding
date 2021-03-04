#include <bits/stdc++.h> 
using namespace std; 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update> 

long long countSubarrays(long long arr[], int n, long long k) 
{ 
    long long start = 0, end = 0, 
        count = 0, sum = arr[0]; 
  
    while (start < n && end < n) { 

        if (sum < k) { 
            end++; 
  
            if (end >= start) 
                count += end - start; 
 
            if (end < n) 
                sum += arr[end]; 
        } 
        else { 
            sum -= arr[start]; 
            start++; 
        } 
    } 
  
    return count; 
} 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	long long arr[n];
    	for(int i=0;i<n;i++)
    	{
    		cin>>arr[i];
		}
		long long c[n];
		map<long long,int> temp;
		ordered_set o_set;
		
		for(int i=0;i<n;i++)
		{
			temp[arr[i]]++;
			c[i]=o_set.find_by_order({-arr[i],-temp[arr[i]]});
			o_set.insert({-arr[i],-temp[arr[i]]});
		}
		for(int i=0;i<n;i++)
		{
			cout<<c[i]<<' ';
		}
	}
} 
