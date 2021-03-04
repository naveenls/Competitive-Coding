#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[n],b[n];
	
	int k;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		k--;
		
		a[k]=i;
	}
	for(int i=0;i<n;i++)
	{
		cin>>k;
		k--;
		
		b[k]=i;
	}
	
	int count[n]={0};
	
	for(int i=0;i<n;i++)
	{
		int temp=(a[i]-b[i]+n)%n;
		count[temp]++;
	}
	int ma=0;
	for(int i=0;i<n;i++)
		ma=max(ma,count[i]);
		
	cout<<ma<<endl;
	return 0;	
}
