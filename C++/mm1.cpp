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
		int row[n]={0};
		int col[m]={0};
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				row[i]+=arr[i][j];
				col[j]+=arr[i][j];
			}
		}
		
		int cnt1=0,cnt2=0;
		for(int i=0;i<n;i++)
		{
			if(row[i]==0)
				cnt1++;
		}
		
		for(int i=0;i<m;i++)
		{
			if(col[i]==0)
				cnt2++;
		}
		int a=min(cnt1,cnt2);
		if(a%2==0)
		{
			cout<<"Vivek"<<endl;
		}
		else
		{
			cout<<"Ashish"<<endl;
		}
	}
	return 0;	
}
