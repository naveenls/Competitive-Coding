#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	long long arr[n];
	long long ans=0;
	
	long long prev_ones=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
		long long temp=min(arr[i]/2,prev_ones);
		prev_ones-=temp;
		
		ans+=temp;
		arr[i]-=2*temp;
		
		ans+=arr[i]/3;
		prev_ones+=arr[i]%3;	
	}
	
	cout<<ans<<endl;
	return 0;
}
