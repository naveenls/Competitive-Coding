#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	int open=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			open++;
		}
	}
	
	if(s.size()%2)
	{
		cout<<":("<<endl;
		return 0;
	}
	
	open=s.size()/2-open;
	
	if(open<0)
	{
		cout<<":("<<endl;
		return 0;
	}
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='?' && open)
		{
			s[i]='(';
			open--;
		}
		else if(s[i]=='?')
		{
			s[i]=')';
		}
	}
	
	if(s[0]==')')
	{
		cout<<":("<<endl;
		return 0;
	}
	
	int cnt=0;

	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]==')')
		{
			cnt--;
		}
		else
		{
			cnt++;
		}
		if(cnt<=0)
		{
			cout<<":("<<endl;
			return 0;
		}
	}
	
	if(s[s.size()-1]==')' && cnt==1)
	{
		cout<<s<<endl;
	}
	else
	{
		cout<<":("<<endl;
	}
	return 0;
}
