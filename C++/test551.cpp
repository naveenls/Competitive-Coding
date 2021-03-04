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
		
		string s;
		cin>>s;
		
		int sum[n+1];
		sum[0]=0;
		
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+s[i-1]-'0';
		}
		
		map<int,long long> mp;
		
		for(int i=0;i<=n;i++)
		{
			sum[i]-=i;			
			mp[sum[i]]++;
		}
		
		mp[sum[0]]--;
		
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(mp.find(sum[i-1])!=mp.end())
			{
				ans+=mp[sum[i-1]];
			}
			mp[sum[i]]--;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
