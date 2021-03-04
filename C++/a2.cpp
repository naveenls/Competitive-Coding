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
		bool flag=0;
		for(int i=1;i<s.size();i++)
		{
			if(s[i]!=s[i-1])
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			cout<<s<<endl;
		}
		else
		{
			string t="";
			for(int i=0;i<s.size();i++)
			{
				t+="10";
			}
			cout<<t<<endl;
		}
	}
	return 0;
}
