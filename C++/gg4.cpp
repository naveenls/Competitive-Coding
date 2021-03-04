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
		long long arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int cnt=0;
		
		for(int i=0;i<n;i++)
		{
			long long mi=arr[i];
			long long ma=arr[i];
			for(int j=i;j<n;j++)
			{
				mi=min(arr[j],mi);
				ma=max(arr[j],ma);
				
				if(ma-mi==abs(arr[i]-arr[j]))
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
