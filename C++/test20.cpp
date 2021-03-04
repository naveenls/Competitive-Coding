#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int j=n-1;
	bool mark[n]={0};
	for(int i=n/2-1;i>=0;i--)
	{
		while(mark[j])
		{
			j--;
		}
		if(arr[j]>=2*arr[i])
		{
			j--;
			mark[i]=1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(!mark[i])
			ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}
