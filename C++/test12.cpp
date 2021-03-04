#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,t;
	cin>>n>>t;
	long long arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int end=n;
	long long sum=0;
	int max_len=0;
	for(int i=n-1;i>=0;i--)
	{
		sum+=arr[i];
		while(sum>t)
		{
			end--;
			sum-=arr[end];
		}
		if(end-i>max_len)
		{
			max_len=end-i;
		}
	}
	cout<<max_len<<endl;
	return 0;
	
}
