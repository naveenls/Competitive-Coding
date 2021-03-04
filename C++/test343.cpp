#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		sort(arr,arr+n);
		
		for(int i=0;i<n-1;i++)
		{
			if(arr[i]>k)
			{
				arr[i+1]-=(arr[i]-k);
				arr[i]=k;
			}
		}
		int sum=0;
		
		for(int i=0;i<n;i++)
		{
			sum+=arr[i];	
		}
		cout<<sum<<endl;
	}
	return 0;
}
