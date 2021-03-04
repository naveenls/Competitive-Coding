#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	int cnt1=0;
	
	for(int i=0;i<s.size();i++)
	{
		cnt1+=(s[i]=='1');
	}
	
	cout<<min(cnt1,(int)s.size()-cnt1+2)<<endl;
	return 0;
}
