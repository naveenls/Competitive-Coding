#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	if(n==m)
	{
		string s="";
		while(n--)
		{
			s+="10";
		}
		cout<<s;
	}
	else if(n==m+1)
	{
		string s="";
		while(m--)
		{
			s+="01";
		}
		cout<<s+"0";
	}
	else if(n>m || m>2*n+2)
	{
		cout<<-1;
		
	}
	else
	{
		string arr[n+1];
		for(int i=0;i<n+1;i++)
			arr[i]="1";
		
		int p=m-n-1;
		for(int i=0;i<p;i++)
		{
			arr[i]+="1";
		}
		string s="";
		for(int i=0;i<n;i++)
		{
			s+=(arr[i]+"0");
		}
		s+=arr[n];
		cout<<s;
	}
	return 0;
	
}
