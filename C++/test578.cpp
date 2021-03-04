#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		
		string ans="";
		
		int i=0;
		
		while(i<2*n-1)
		{
			ans.push_back(s[i]);
			i+=2;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
