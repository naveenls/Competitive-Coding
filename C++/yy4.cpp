#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		int arr[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				arr[i][j]=0;
		}
		
		vector<int> v(n);
		for(int i=0;i<n;i++)
		{
			v[i]=k/n;
		}
		for(int i=0;i<k%n;i++)
		{
			v[i]++;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<i+v[i];j++)
			{
				int ind=j%n;
				arr[i][ind]=1;
			}
		}
		int mi=n;
		int ma=0;
		
		int mi1=n;
		int ma1=0;
		
		for(int i=0;i<n;i++)
		{
			int sum=0;
			int sum1=0;
			
			for(int j=0;j<n;j++)
			{
				sum+=arr[i][j];
				sum1+=arr[j][i];
			}
			
			mi=min(sum,mi);
			ma=max(sum,ma);
			
			mi1=min(sum,mi1);
			ma1=max(sum,ma1);
		}
		
		cout<<(ma-mi)*(ma-mi) + (ma1-mi1)*(ma1-mi1)<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<arr[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
