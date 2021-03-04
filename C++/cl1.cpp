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
		
		int a;
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			if(a%2==0)
				flag=1;
		}
		if(flag)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
