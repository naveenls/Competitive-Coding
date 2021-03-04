#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		string arr[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		int cnt=0;
		
		for(int i=0;i<m-1;i++)
		{
			if(arr[n-1][i]=='D')
				cnt++;
		}
		
		for(int i=0;i<n-1;i++)
		{
			if(arr[i][m-1]=='R')
				cnt++;
		}
		
		cout<<cnt<<endl;
	}
	return 0;
}
