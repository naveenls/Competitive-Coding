#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k;
	
	cin>>n>>m>>k;
	
	int initial_n=n;
	int initial_m=m;
	
	int gcd=__gcd(n,k);
	n/=gcd;
	k/=gcd;
	
	gcd=__gcd(m,k);
	m/=gcd;
	k/=gcd;
	
	if(k==1)
	{
		cout<<"YES"<<endl;
		if(2*n<=initial_n)
		{
			cout<<0<<' '<<0<<endl;
			cout<<2*n<<' '<<0<<endl;
			cout<<2*n<<' '<<m<<endl;
		}
		else
		{
			cout<<0<<' '<<0<<endl;
			cout<<n<<' '<<0<<endl;
			cout<<n<<' '<<2*m<<endl;
		}
	}
	else if(k==2)
	{
		cout<<"YES"<<endl;
		
		cout<<0<<' '<<0<<endl;
		cout<<n<<' '<<0<<endl;
		cout<<n<<' '<<m<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
