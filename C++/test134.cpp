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
	
	int mi[n];
	mi[n-1]=arr[n-1];
	
	for(int i=n-2;i>=0;i--)
	{
		mi[i]=min(mi[i+1],arr[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		int ind=upper_bound(mi,mi+n,arr[i]-1)-mi;
		ind--;
		if(ind<=i || mi[ind]>=arr[i])
		{
			cout<<-1<<' ';
		}
		else
		{
			cout<<ind-i-1<<' ';
		}
	}
	return 0;
}
