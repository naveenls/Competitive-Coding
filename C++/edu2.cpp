#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string str;
		cin>>str;
		
		int r=0,p=0,s=0;
		for(int i=0;i<str.size();i++)
		{
			r+=(str[i]=='R');
			p+=(str[i]=='P');
			s+=(str[i]=='S');
		}
		
		int n=str.size();
		
		if(r>=p && r>=s)
		{
			string temp(n,'P');
			cout<<temp<<endl;
		}
		else if(p>=r && p>=s)
		{
			string temp(n,'S');
			cout<<temp<<endl;
		}
		else
		{
			string temp(n,'R');
			cout<<temp<<endl;
		}
	}
	return 0;
}
