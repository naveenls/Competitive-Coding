#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,d;
	cin>>n>>d;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		int ind=upper_bound(arr,arr+n,arr[i]+d) - arr;
		ind--;
		
		int len=ind-i+1;
		if(len>2)
		{
			ans+=(long long)(len-2)*(len-1)/2;
		}
	}
	cout<<ans<<endl;
}
