#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	string ans="";
	for(int i=0;i<n;i++)
	{
		if(s[i]=='r')
			ans+=(to_string(i+1)+'\n');
	}
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='l')
		{
			ans+=(to_string(i+1)+'\n');
		}
	}
	cout<<ans<<endl;
	return 0;
}
