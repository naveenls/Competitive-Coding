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
		
		int l=-1;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
				break;
			l=i;
		}
		
		int r=n;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='0')
				break;
			r=i;
		}
		
		if(r==l+1)
		{
			cout<<s<<endl;
		}
		else
		{
			for(int i=0;i<=l;i++)
			{
				cout<<s[i];
			}
			cout<<0;
			for(int i=r;i<n;i++)
			{
				cout<<s[i];
			}
			cout<<endl;
		}
	}
	return 0;
}
