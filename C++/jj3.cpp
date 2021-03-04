#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		bool flag=0;
		
		int i=n-2;
		for(;i>=0;i--)
		{
			if(!flag)
			{
				if(arr[i]<arr[i+1])
				{
					flag=1;
				}
			}
			else
			{
				if(arr[i]>arr[i+1])
				{
					break;
				}
			}
		}
		
		cout<<i+1<<endl;
	}
	return 0;
}
