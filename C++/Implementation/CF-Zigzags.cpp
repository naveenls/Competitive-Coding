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
		
		int arr[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			arr[i]--;			
		}
		
		long long ans=0;
		
		for(int i=0;i<n;i++)
		{
			long long l_cnt[n]={0};
			long long r_cnt[n]={0};
			
			for(int j=i+1;j<n;j++)
			{
				r_cnt[arr[j]]++;
			}
			
			long long prod_sum=0;
			
			for(int j=i+1;j<n;j++)
			{
				prod_sum-=l_cnt[arr[j]]*r_cnt[arr[j]];
				
				l_cnt[arr[j]]++;
				r_cnt[arr[j]]--;
				
				prod_sum+=l_cnt[arr[j]]*r_cnt[arr[j]];
				
				if(arr[i]==arr[j])
				{
					ans += prod_sum;
					ans-= r_cnt[arr[i]];
				}				
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
