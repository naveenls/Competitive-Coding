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
		
		long long arr[n+1];
		arr[0]=0;
		
		long long t_sum=0;
		
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];			
		}
		
		for(int j=0;j<30;j++)
		{
			long long val=(1LL<<j);
			
			int cnt1=0;
			int cnt0=0;
			
			int temp[n+1];
			temp[0]=0;
			
			for(int i=1;i<=n;i++)
			{
				if(arr[i] & val)
				{
					temp[i]=(temp[i-1] + 1)%2;
				}
				else
				{
					temp[i]=temp[i-1];
				}
				
				if(temp[i])
					cnt1++;
				else
					cnt0++;
			}
			
			long long t_cnt=0;
			
			for(int i=1;i<=n;i++)
			{
				if(temp[i-1])
				{
					t_cnt+=cnt0;	
				}
				else
				{
					t_cnt+=cnt1;
				}
				
				if(temp[i])
				{
					cnt1--;
				}
				else
				{
					cnt0--;
				}
			}
			
			t_sum+=val*t_cnt;
		}
		
		cout<<t_sum<<endl;
	}
	return 0;
}
