#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int r,b,k;
		cin>>r>>b>>k;
		
		if(r>b)
			swap(r,b);
		
		int gcd=__gcd(r,b);
		r/=gcd;
		b/=gcd;
		
		if(k<=(b-1)/r)
		{
			cout<<"REBEL"<<endl;
		}	
		else
			cout<<"OBEY"<<endl;
	}
	return 0;
}
