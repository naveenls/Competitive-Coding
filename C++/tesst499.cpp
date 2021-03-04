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
		
		int ans[n];
		
		for(int i=0;i<n;i++)
		{
			ans[i]=9;
		}
		
		int k=(n+3)/4;
		
		int j=n-1;
		while(k--)
		{
			ans[j]=8;
			j--;
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}
