#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	map<pair<int,int>,long long> mp;
	mp[{0,0}]++;
	
	int st=0,e=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A')
		{
			st+=2;
		}
		else if(s[i]=='B')
		{
			st--;
			e++;
		}
		else
		{
			st--;
			e--;
		}
		mp[{st,e}]++;
	}
	
	long long ans=0;
	for(auto ele:mp)
	{
		ans+=(ele.second)*(ele.second-1)/2;
	}
	
	cout<<ans<<endl;
	return 0;
}
