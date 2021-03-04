#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum=0;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	int pre_sum=0;
	int count=0;
	for(int i=0;i<n-1;i++)
	{
		pre_sum+=arr[i];
		sum-=arr[i];
		if(sum==pre_sum)
			count++;
	}
	cout<<count<<endl;
	return 0;
}
