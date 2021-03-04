#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		
		if(b%a!=0 && a%b!=0)
		{
			cout<<-1<<endl;
			continue;
		}
		if(b<a)
		{
			long long t=a/b;
			int cnt=0;
			
			while(t%2==0)
			{
				cnt++;
				t/=2;
			}
			
			if(t==1)
			{
				cout<<(cnt+2)/3<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
		}
		else if(b>a)
		{
			long long t=b/a;
			int cnt=0;
			
			while(t%2==0)
			{
				cnt++;
				t/=2;
			}
			
			if(t==1)
			{
				cout<<(cnt+2)/3<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
	
}
