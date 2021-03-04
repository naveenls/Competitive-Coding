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
		int sorted[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sorted[i]=arr[i];
		}
		
		sort(sorted,sorted+n);
		
		bool flag=0;
		
		for(int i=0;i<n;i++)
		{
			if(arr[i]!=sorted[i])
			{
				if(arr[i]%sorted[0])
				{
					flag=1;
					break;
				}
			}
		}
		
		if(flag)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
