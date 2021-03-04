#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,f;
		cin>>n>>f;
		
		map<long long,long long> mp;
		
		long long temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			mp[temp]++;	
		}
		
		long long ans=0;
		
		for(auto ele:mp)
		{
			long long cnt=0;
			
			long long start=f*ele.first;
			
			while(start<=1e9)
			{
				if(mp.find(start)!=mp.end())
					cnt+=mp[start];
					
				start*=f;
			}
			
			ans+=cnt*ele.second;
			ans+=(ele.second)*(ele.second-1)/2;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
