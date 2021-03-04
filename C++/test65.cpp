#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	bool flag=1;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]!=1)
			flag=0;
	}
	if(flag)
	{
		for(int i=0;i<n-1;i++)
			cout<<1<<' ';
		cout<<2;
		return 0;
	}
	sort(arr,arr+n);

	int mi=1;
	for(int i=0;i<n;i++)
	{
		cout<<mi<<' ';
		mi=arr[i];
	}
	
	return 0;
}
