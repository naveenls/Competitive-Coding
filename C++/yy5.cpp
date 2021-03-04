#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

ordered_set o_set;

void perm_to_fact(int perm[],int fact[],int n)
{
	for(int i=0;i<n;i++)
		o_set.insert(i);
		
	for(int i=0;i<n;i++)
	{
		fact[n-i-1]=o_set.order_of_key(perm[i]);
		o_set.erase(perm[i]);
	}
}

int main()
{
	
	int p,n;
	cin>>n>>p;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];	
	}
	
	sort(arr,arr+n);
	
	int mi_x=0;
	for(int i=0;i<n;i++)
	{
		mi_x=max(mi_x,arr[i]-i);
	}
	
	int mod[n];
	mod[0]=1;
	
	for(int i=1;i<n;i++)
	{
		mod[i]=(mod[i-1]*i)%p;	
	}
	
	int ma_x=arr[n-1];
	
	int fact[n];
	
	set<int> aa;
	
	for(int x=mi_x;x<=ma_x;x++)
	{
		int left[n];
		int ans[n];
		
		int count=0;
		
		for(int i=0;i<n;i++)
		{
			int temp=max(0,arr[i]-i);
			
			left[i]=max(0,i-(x-temp));
			ans[i]=-1;
			
		}
		for(int i=n-1;i>=0;i--)
		{
			int ind=left[i];
			while(ans[ind]!=-1)
			{
				ind++;
			}
			ans[ind]=i;
		}
		
		perm_to_fact(ans,fact,n);
		for(int i=0;i<n;i++)
		{
			count=(count+mod[i]*fact[i])%p;
		}
		count=(count+1)%p;
		
		if(count)
		{
			aa.insert(x);
		}
	}
	
	cout<<aa.size()<<endl;
	for(auto ele: aa)
	{
		cout<<ele<<' ';
	}
	return 0;
}
