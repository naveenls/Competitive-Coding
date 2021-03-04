#include<bits/stdc++.h>
using namespace std;

bool check_prime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		if(n==1)
		{
			cout<<"FastestFinger"<<endl;
		}
		else if(n==2)
		{
			cout<<"Ashishgup"<<endl;
		}
		else
		{
			int temp=n;
			int cnt=0;
			while(temp%2==0)
			{
				temp/=2;
				cnt++;
			}
			
			if(temp==1)
			{
				cout<<"FastestFinger"<<endl;
			}
			else if(cnt>1)
			{
				cout<<"Ashishgup"<<endl;
			}
			else if(cnt==0)
			{
				cout<<"Ashishgup"<<endl;
			}
			else
			{
				if(check_prime(temp))
				{
					cout<<"FastestFinger"<<endl;
				}
				else
				{
					cout<<"Ashishgup"<<endl;
				}
			}
		}
	}
	return 0;
}
