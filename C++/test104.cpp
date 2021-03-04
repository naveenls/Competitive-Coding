#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int to[n];
	for(int i=0;i<(n+1)/2;i++)
	{
		to[i]=i+1;
		to[n-i-1]=to[i];
	}
	const int maxN=1e5+1;
	int temp[maxN]={0};
	
	for(int i=0;i<n;i++)
	{
		//cout<<to[i]<<' '<<arr[i]<<endl;
		int c=arr[i]-to[i];
		if(c>=0)
		{
			//cout<<c<<endl;
			temp[c]++;
		}
	}
	int ma=0;
	for(int i=0;i<maxN;i++)
	{
		ma=max(ma,temp[i]);
	}
	cout<<n-ma<<endl;
	return 0;
}
