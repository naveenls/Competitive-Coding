#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long double h,c,t;
		cin>>h>>c>>t;
		
		if(2*t<=(c+h))
		{
			cout<<2<<endl;
		}
		else
		{
			long double r=(h-t);
			long double d=2*t-(c+h);
			long double ans=ceil(r/d);
			long double ans1=floor(r/d);
			
			long double val1=abs((ans*(c+h)+h)/(2*ans+1)-t);
			long double val2=abs((ans1*(c+h)+h)/(2*ans1+1)-t);
			
			long double val3=abs(t-(c+h)/2);
			if(val3<=val1 && val3<=val2)
			{
				cout<<2<<endl;
			}
			else if(val2<=val1 && val2<=val3)
			{
				cout<<(long long)2*ans1+1<<endl;
			}
			else
			{
				cout<<(long long)2*ans+1<<endl;
			}
		}
	}
	return 0;
}
