#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		
		int cnt=0;
		for(int i=0;i<s.size();i++)
		{
			cnt+=(s[i]=='1');
		}
		cnt=min(cnt,(int)s.size()-cnt);
		
		if(cnt%2)
		{
			cout<<"DA"<<endl;
		}
		else
		{
			cout<<"NET"<<endl;
		}
	}
	return 0;
}
