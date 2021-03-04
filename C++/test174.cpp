#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	if(n*m%2)
	{
		cout<<1<<endl;
		cout<<n<<' '<<m<<' '<<1<<' '<<1<<endl;
		bool flag=0;
		
		for(int i=1;i<=n;i++)
		{
			if(flag==0)
			{
				for(int j=1;j<=m;j++)
					cout<<i<<' '<<j<<endl;
				flag=1;
			}
			else
			{
				for(int j=m;j>=1;j--)
					cout<<i<<' '<<j<<endl;
					
				flag=0;
			}
		}
		cout<<1<<' '<<1<<endl;
	}
	else
	{
		if(n%2==0)
		{
			if(m==1 && n!=2)
			{
				cout<<1<<endl;
				cout<<n<<' '<<m<<' '<<1<<' '<<1<<endl;
				for(int j=1;j<=n;j++)
				{
					cout<<j<<' '<<1<<endl;
				}
				cout<<1<<' '<<1<<endl;
				return 0;
			}
			cout<<0<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<i<<' '<<1<<endl;
			}
			
			bool flag=0;
			for(int i=n;i>=1;i--)
			{
				if(flag==0)
				{
					for(int j=2;j<=m;j++)
						cout<<i<<' '<<j<<endl;
					flag=1;
				}
				else
				{
					for(int j=m;j>=2;j--)
						cout<<i<<' '<<j<<endl;
						
					flag=0;
				}
			}
			cout<<1<<' '<<1<<endl;
		}
		else
		{
			if(n==1 && m!=2)
			{
				cout<<1<<endl;
				cout<<n<<' '<<m<<' '<<1<<' '<<1<<endl;
				for(int j=1;j<=m;j++)
				{
					cout<<1<<' '<<j<<endl;
				}
				cout<<1<<' '<<1<<endl;
				return 0;
			}
			cout<<0<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<i<<' '<<1<<endl;
			}
			
			bool flag=1;
			for(int j=2;j<=m;j++)
			{
				if(flag==0)
				{
					for(int i=2;i<=n;i++)
						cout<<i<<' '<<j<<endl;
					flag=1;
				}
				else
				{
					for(int i=n;i>=2;i--)
						cout<<i<<' '<<j<<endl;
						
					flag=0;
				}
			}
			for(int j=m;j>=1;j--)
			{
				cout<<1<<' '<<j<<endl;
			}
		}
	}
	return 0;
}
