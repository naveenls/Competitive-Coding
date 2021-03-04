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
			
			if(i%2==0)
			{
				arr[i]=abs(arr[i]);
			}
			else
			{
				arr[i]=-1*abs(arr[i]);
			}
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
