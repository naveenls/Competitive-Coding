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
		
		if(n<=30)
		{
			cout<<"NO"<<endl;
		}
		else if(n==36)
		{
			cout<<"YES"<<endl;
			cout<<5<<' '<<6<<' '<<10<<' '<<15<<endl;
		}
		else if(n==40)
		{
			cout<<"YES"<<endl;
			cout<<6<<' '<<15<<' '<<10<<' '<<9<<endl;
		}
		else if(n==44)
		{
			cout<<"YES"<<endl;
			cout<<6<<' '<<7<<' '<<10<<' '<<21<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<6<<' '<<14<<' '<<10<<' '<<n-30<<endl;
		}
	}
	return 0;
}
