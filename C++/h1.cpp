#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if(n>m)
			swap(n,m);
			
		if(n%2)
		{
			if(m%2)
			{
				cout<<(n)*(m/2) + n-n/2;
			}
			else
			{
				cout<<(n)*(m/2);
			}
		}
		else
		{
			if(m%2)
			{
				cout<<(n)*(m/2) + n/2;
			}
			else
			{
				cout<<(n/2)*m;
			}
		}
		cout<<endl;	
	}
	return 0;
}
