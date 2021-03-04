#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		
		if(c<=d)
		{
			if(b<a)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<b<<endl;
			}
		}
		else
		{
			if(b>=a)
			{
				cout<<b<<endl;
			}
			else
			{
				long long temp=c-d;
				long long t1=(a-b+temp-1)/temp;
				cout<<b+t1*c<<endl;
			}
		}
		
		
	}
	return 0;
}
