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
		
		int i=0;
		
		for(;i<n;i++)
		{
			if(arr[i]!=1)
				break;
				
			flag=1-flag;	
		}
		
		if(i==n)
			flag=1-flag;
			
		if(flag==0)
		{
			cout<<"First"<<endl;
		}
		else
		{
			cout<<"Second"<<endl;
		}
	}
	
	return 0;
}
