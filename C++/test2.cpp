#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int m;
	cin>>m;
	int l,r;
	int n=s.size();
	int arr[n+1];
	arr[n]=0;
	for(int i=n-1;i>=1;i--)
	{
		arr[i]=arr[i+1]+(s[i-1]==s[i]);
	}
	for(int i=0;i<m;i++)
	{
		cin>>l>>r;
		cout<<arr[l]-arr[r]<<endl;
	}
	
	return 0;
}
