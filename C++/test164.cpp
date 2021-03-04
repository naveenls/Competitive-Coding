#include<bits/stdc++.h>

using namespace std;

int main()
{
	long double s;
	cin>>s;
	
	long double a,b,c;
	cin>>a>>b>>c;
	
	long double x=a*s/(a+b+c);
	long double y=b*s/(a+b+c);
	long double z=c*s/(a+b+c);
	
	if(a+b+c==0)
	{
		cout<<fixed<<setprecision(10)<<0<<' '<<0<<' '<<0<<endl;
		return 0;
	}
	cout<<fixed<<setprecision(10)<<x<<' '<<y<<' '<<z<<endl;
	return 0;
}
