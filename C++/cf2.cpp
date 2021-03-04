#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		long long x;
		cin>>n>>x;
		
		long long arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		long long DP[n+1]={0};
		DP[0]=0;
		
		for(int i=1;i<=n;i++)
			DP[i]=arr[i-1]+DP[i-1];
			
		vector<int> factors;
		for(int i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				factors.push_back(i);
			}
		}
		
		//cout<<factors.size()<<endl;
		
		long long ans=0;
		
		for(auto l:factors)
		{
			if(l>n)
				continue;
				
			long long rem=x/l;
			
			int tt[rem]={0};
			
			long long sum;
			for(int i=1;i<=n-l+1;i++)
			{
				int j=i+l-1;
				sum=DP[j]-DP[i-1];
				
				if(sum<rem)
					ans+=(long long)2*tt[rem-sum];
				
				if(rem==2*sum)
					ans++;
					
				if(sum<rem)
					tt[sum]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
