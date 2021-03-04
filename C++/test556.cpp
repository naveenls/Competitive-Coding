#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		long long k;
		
		cin>>n>>k;
		
		int ma=-1e9;

		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			ma=max(ma,arr[i]);
		}
		
		int t1[n];
		int ma1=-2e9;
		
		for(int i=0;i<n;i++)
		{
			t1[i]=ma-arr[i];
			ma1=max(ma1,t1[i]);
		}
		
		int t2[n];
		for(int i=0;i<n;i++)
		{
			t2[i]=ma1-t1[i];
		}
		
		if(k==0)
		{
			for(int i=0;i<n;i++)
			{
				cout<<arr[i]<<' ';
			}
			cout<<endl;
		}
		else if(k%2)
		{
			for(int i=0;i<n;i++)
			{
				cout<<t1[i]<<' ';
			}
			cout<<endl;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				cout<<t2[i]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
