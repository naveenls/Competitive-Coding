#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n][20];
	int temp;
	
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		
		for(int j=0;j<20;j++)
		{
			arr[i][j]=temp%2;
			temp/=2;
		}
	}
	
	int cnt[20]={0};
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<20;j++)
		{
			cnt[j]+=arr[i][j];
		}
	}
	
	int ans[n][20];
	memset(ans,0,sizeof(ans));
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<20;j++)
		{
			//cout<<cnt[j]<<endl;
			if(cnt[j])
			{
				ans[i][j]=1;
				cnt[j]--;
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<20;j++)
		{
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	long long ans_end=0;
	
	for(int i=0;i<n;i++)
	{
		long long val=0;
		
		long long p=1;
		for(int j=0;j<20;j++)
		{
			if(ans[i][j])
			{
				val+=p;
			}
			p*=2;
		}
		
		ans_end+=val*val;
	}
	cout<<ans_end<<endl;
	return 0;
}
