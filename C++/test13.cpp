#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int l,r;
	int diff[n+1]={0};
	for(int i=0;i<q;i++)
	{
		cin>>l>>r,l--,r--;
		diff[l]++;
		diff[r+1]--;
	}
	for(int i=1;i<n;i++)
	{
		diff[i]+=diff[i-1];
	}
	sort(diff,diff+n);
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=(long long)diff[i]*arr[i];
	}
	cout<<sum<<endl;
	return 0;
	
}
