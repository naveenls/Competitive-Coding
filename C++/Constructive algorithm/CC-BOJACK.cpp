#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int d;
		cin>>d;
		
		string ans="";
		
		int temp=d;
		while(temp--)
		{
			ans.push_back('a');
		}
		
		temp=d;
		while(temp--)
		{
			ans.push_back('b');
		}
		cout<<2*d<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
