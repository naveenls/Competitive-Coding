#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	vector<pair<int,int> > v;
	
	int DP[n];
	DP[0]=0;
	int start=0;
	
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
		{
			DP[i]=DP[i-1]+1;
		}
		else
		{
			if(start<i-2)
			{
				v.push_back({start,i-1});
			}
			
			DP[i]=0;
			start=i;
		}
	}
	
	if(start<n-2)
	{
		v.push_back({start,n-1});
	}
	
	int ma=0;
	for(int i=0;i<n;i++)
	{
		ma=max(ma,DP[i]);
	}
	
	cout<<ma/2<<endl;
	
	for(auto pr:v)
	{
		int s=pr.first;
		int e=pr.second;
		
		int a=arr[s],b=arr[e];
		
		while(s<=e)
		{
			arr[s]=a;
			arr[e]=b;
			
			s++;
			e--;	
		}
	}
	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';
		
	return 0;
}
