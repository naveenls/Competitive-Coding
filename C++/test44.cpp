#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;
int main()
{
	int n,m;
	cin>>n>>m;
	set<char> s[m];
	char c;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>c;
			s[j].insert(c);
		}
	}
	long long ans=1;
	for(int i=0;i<m;i++)
	{
		ans=(ans*s[i].size())%mod;
	}
	cout<<ans<<endl;
	return 0;
}
