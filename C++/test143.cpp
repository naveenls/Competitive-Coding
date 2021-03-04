#include<bits/stdc++.h>
using namespace std;

int main()
{
	long double a,b;
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		long double x=min(a/4,b);
		if(a!=0 && b!=0)
			cout<<fixed<<setprecision(10)<<(b*a+ a*x-2*x*x)/(2*a*b)<<endl;
		else if(a==0 && b==0)
			cout<<fixed<<setprecision(10)<<1.0<<endl;
		else if(a==0 && b!=0)
			cout<<fixed<<setprecision(10)<<0.5<<endl;
		else
			cout<<fixed<<setprecision(10)<<1.0<<endl;
	}
	return 0;
}
