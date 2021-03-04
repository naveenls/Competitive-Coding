#include<bits/stdc++.h>
using namespace std;

long long mod=1e15+7;

long long hash_val(string &s)
{
	long long val=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		val=(val*26 + s[i]-'a' + 1)%mod;
	}
	
	return val;
}

int main()
{
	int n;
	cin>>n;
	
	string s[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i];	
	}
	
	map<long long,int> mp;
	
	long long ans=0;
	
	for(int i=0;i<n;i++)
	{
		long long initial=0;
		
		for(int j=s[i].size()-1;j>0;j--)
		{
			initial=(initial*26 + s[i][j]-'a'+1)%mod;
			
			if(mp.find(initial)!=mp.end())
			{
				ans+=mp[initial];
			}
			
			long long temp=(initial*26 + s[i][0]-'a'+1)%mod;
			
			if(mp.find(temp)!=mp.end())
			{
				ans+=mp[temp];
			}
		}
		
		initial=s[i][0]-'a'+1;
		if(mp.find(initial)!=mp.end())
		{
			ans+=mp[initial];
		}
		
		mp[hash_val(s[i])]++;	
	}
	
	mp.clear();
	
	for(int i=n-1;i>=0;i--)
	{
		long long initial=0;
		
		for(int j=s[i].size()-1;j>0;j--)
		{
			initial=(initial*26 + s[i][j]-'a'+1)%mod;
			
			if(mp.find(initial)!=mp.end())
			{
				ans+=mp[initial];
			}
			
			long long temp=(initial*26 + s[i][0]-'a'+1)%mod;
			
			if(mp.find(temp)!=mp.end())
			{
				ans+=mp[temp];
			}
		}
		
		initial=s[i][0]-'a'+1;
		if(mp.find(initial)!=mp.end())
		{
			ans+=mp[initial];
		}
		
		mp[hash_val(s[i])]++;	
	}
	
	cout<<ans<<endl;
	return 0;
}
