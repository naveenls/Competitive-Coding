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
		{
			cin>>arr[i];
			if(i)
				arr[i]+=arr[i-1];
			
			arr[i]%=n;
		}
		
		map<int,int> mp;
		
		for(int i=0;i<n;i++)
		{
			if(arr[i]==0)
			{
				cout<<i+1<<endl;
				
				for(int j=0;j<=i;j++)
				{
					cout<<j+1<<' ';
				}
				cout<<endl;
				break;
			}
			if(mp.find(arr[i])!=mp.end())
			{
				cout<<i-mp[arr[i]]<<endl;
				
				for(int j=mp[arr[i]]+1;j<=i;j++)
				{
					cout<<j+1<<' ';
				}
				cout<<endl;
				break;
			}
			mp[arr[i]]=i;
		}
	}
	return 0;
}
