#include<iostream>
using namespace std;

int main()
{
	int a,m;
	cin>>a>>m;
	a=a%m;
	int temp=m;
	while(temp%2==0)
	{
		temp/=2;
	}
	if(a==0 || temp==1)
	{
		cout<<"Yes"<<endl;
	}
	else if(m%a)
	{
		cout<<"No"<<endl;
	}
	else
	{
		int p=m/a;
		while(p%2==0)
		{
			p/=2;
		}
		if(p==1)
		{
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
	}
}
