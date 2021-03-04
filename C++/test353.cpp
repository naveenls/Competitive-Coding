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
				
		if(n%2)
		{
			cout<<"NO"<<endl;
			continue;
		}
		
		bool flag=0;
		
		for(int i=0;i<n/2;i++)
		{
			if(arr[i]==-1 && arr[n/2+i]==-1)
			{
				arr[i]=arr[n/2+i]=1;
			}
			else if(arr[i]==-1)
			{
				arr[i]=arr[n/2+i];
			}
			else if(arr[n/2+i]==-1)
			{
				arr[n/2+i]=arr[i];
			}
			else if(arr[i]!=arr[n/2+i])
			{
				flag=1;
				break;
			}
		}
		
		if(flag)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			
			for(int i=0;i<n;i++)
				cout<<arr[i]<<' ';
			
			cout<<endl;
		}
	}
	return 0;
}
