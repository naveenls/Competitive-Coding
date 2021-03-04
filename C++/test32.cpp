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
	bool flag=0;
	int ind=-1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			flag=1;
			ind=i;
			break;
		}
	}
	if(!flag)
	{
		cout<<0;
		return 0;
	}
	for(int i=ind+1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			flag=0;
			break;
		}
	}
	if(!flag || arr[n-1]>arr[0])
	{
		cout<<-1;
	}
	else
	{
		cout<<n-ind;
		
	}
}
