#include<bits/stdc++.h>
using namespace std;
;
int main()
{
	int n;
	cin>>n;
	
	long long arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	long long c[5];
	for(int i=0;i<5;i++)
	{
		cin>>c[i];
	}
	long long ans[5]={0};
	long long total_sum=0;
	for(int i=0;i<n;i++)
	{
		total_sum+=arr[i];
		for(int j=4;j>=0;j--)
		{
			long long temp=total_sum/c[j];
			ans[j]+=temp;
			total_sum-=c[j]*temp;
		}
	}
	for(int i=0;i<5;i++)
		cout<<ans[i]<<' ';
	cout<<endl<<total_sum;
	return 0;
}
