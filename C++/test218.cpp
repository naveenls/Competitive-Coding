#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b;
	cin>>a>>b;
	
	long long temp1=a;
	long long temp2=b;
	
	long long gcd=__gcd(a,b);
	
	long long min_val=1e18;
	long long min_k=0;
	
	long long pre_gcd=-1;
	while(true)
	{
		long long gcd=__gcd(a,b);
	
		//cout<<a<<' '<<b<<endl;
		if(gcd==pre_gcd)
		{
			cout<<min_k<<endl;
			return 0;	
		}
		else
		{
			if((a*b)/gcd < min_val)
			{
				min_val=(a*b)/gcd;
				min_k=a-temp1;
			}
			a+=gcd;
			b+=gcd;
		}
		pre_gcd=gcd;
	}
	return 0;
}
