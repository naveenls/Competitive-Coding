#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long arr[26];
	
	for(int i=0;i<26;i++)
		cin>>arr[i];
		
	string s;
	cin>>s;
	
	long long DP[s.size()+1];
	DP[0]=0;
	
	for(int i=1;i<=s.size();i++)
	{
		DP[i]=DP[i-1]+arr[s[i-1]-'a'];
	}
	map<long long,vector<int> > mp[26];
	
	for(int i=1;i<=s.size();i++)
	{
		mp[s[i-1]-'a'][DP[i]].push_back(i);
	}
	
	long long ans=0;
	for(int i=1;i<s.size();i++)
	{
		long long nxt=DP[i]+arr[s[i-1]-'a'];
		
		if(mp[s[i-1]-'a'][nxt].size())
		{
			int ind=lower_bound(mp[s[i-1]-'a'][nxt].begin(),mp[s[i-1]-'a'][nxt].end(),i+1)-mp[s[i-1]-'a'][nxt].begin();
			ans+=(mp[s[i-1]-'a'][nxt].size()-ind);	
		}
	}
	cout<<ans<<endl;
	return 0;
}
