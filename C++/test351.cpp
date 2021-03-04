#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,l;
	cin>>n>>l;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int ind=-1;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]+arr[i+1]>=l)
		{
			ind =i;
			break;
		}
	}
	
	if(ind==-1)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		cout<<"Possible"<<endl;
		
		for(int i=1;i<=ind;i++)
		{
			cout<<i<<endl;
		}
		
		for(int i=n-1;i>=ind+2;i--)
		{
			cout<<i<<endl;
		}
		cout<<ind+1<<endl;
	}
	return 0;
}
