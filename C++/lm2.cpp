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
		
		int arr[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		}
		
		int ans[n][m];
		for(int i=0;i<n;i++)
		{
			ans[i][0]=3;
			ans[i][m-1]=3;
		}
		
		for(int i=0;i<m;i++)
		{
			ans[0][i]=3;
			ans[n-1][i]=3;
		}
		
		ans[0][0]=2;
		ans[0][m-1]=2;
		ans[n-1][0]=2;
		ans[n-1][m-1]=2;
		
		for(int i=1;i<n-1;i++)
		{
			for(int j=1;j<m-1;j++)
			{
				ans[i][j]=4;
			}
		}
		
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]>ans[i][j])
				{
					flag=1;
					break;	
				}
			}
			if(flag)
				break;
		}
		
		if(flag)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
					cout<<ans[i][j]<<' ';
				cout<<endl;
			}
		}
	}
	return 0;
}
