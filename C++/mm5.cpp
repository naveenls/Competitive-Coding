#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int n;
	cin>>n;
	
	long long arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	if(n==1)
	{
		cout<<arr[0]<<endl;
		return 0;
	}
	else if(n==2)
	{
		long long temp= arr[0] | arr[1];
		cout<<temp<<endl;		
		return 0;
	}
	long long ma=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				long long temp= arr[i] | arr[j] | arr[k];
				ma=max(ma,temp);
			}
		}
	}
	cout<<ma<<endl;
	return 0;	
}
