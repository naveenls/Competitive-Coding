#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	long long arr[n];
	
	multiset<long long> l_set;
	multiset<long long> r_set;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	long long l_sum=0,r_sum=0;
	
	for(int i=0;i<n;i++)
	{
		r_set.insert(arr[i]);
		r_sum+=arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
		l_set.insert(arr[i]);
		l_sum+=arr[i];
		
		r_set.erase(r_set.find(arr[i]));
		r_sum-=arr[i];
		
		if(l_sum>r_sum)
		{
			long long diff=l_sum-r_sum;
			
			if(diff%2==0)
			{
				if(l_set.find(diff/2)!=l_set.end())
				{
					cout<<"YES";
					return 0;	
				}	
			}
		}
		else if(l_sum<r_sum)
		{
			long long diff=r_sum-l_sum;
			
			if(diff%2==0)
			{
				if(r_set.find(diff/2)!=r_set.end())
				{
					cout<<"YES";
					return 0;	
				}	
			}
		}
		else
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
