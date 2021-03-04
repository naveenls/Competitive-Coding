#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n+1];
	
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	arr[0]=0;
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<arr[i+1])
		{
			long long l=arr[i+1]-arr[i];
			long long r=n-arr[i+1]+1;
			
			//cout<<l<<' '<<r<<endl;
			ans+=l*r;
		}
		else if(arr[i]>arr[i+1])
		{
			long long l=arr[i+1];
			long long r=arr[i]-arr[i+1];
			
			//cout<<l<<' '<<r<<endl;
			ans+=l*r;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
