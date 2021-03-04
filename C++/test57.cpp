#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long arr[n];
	long long sum=0;
	long long ma=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
		ma=max(ma,arr[i]);
	}
	cout<<max(ma,(sum+n-2)/(n-1))<<endl;
	return 0;
}
