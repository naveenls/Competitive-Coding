#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	string arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(arr[i][j]=='.' && arr[i+1][j]=='.' && arr[i-1][j]=='.' && arr[i][j-1]=='.' && arr[i][j+1]=='.')
			{
				arr[i][j]='#';
				arr[i+1][j]='#';
				arr[i-1][j]='#';
				arr[i][j-1]='#';
				arr[i][j+1]='#';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]=='.')
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
