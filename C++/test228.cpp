#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,z;
	cin>>n>>z;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	
	int s=n/2;
	int cnt=0;
	
	for(int i=0;i<n/2;i++)
	{
		while(s<n && arr[s]-arr[i]<z)
			s++;
			
		if(s==n)
			break;
		
		cnt++;
		s++;	
	}
	cout<<cnt<<endl
	return 0;
}
