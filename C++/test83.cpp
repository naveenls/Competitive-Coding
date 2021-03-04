#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    cin>>a>>b;
    
    long long l=0;
    long long r=0;
    
    long long t=a;
    long long t1=b;
    long long start=0;
    
    long long _lcm=(a*b)/__gcd(a,b);
    
    while(t<_lcm || t1<_lcm)
    {
    	//cout<<t<<' '<<t1<<' '<<start<<endl;
    	if(t<t1)
    	{
    		
    		l+=(t-start);
    		start=t;
    		t+=a;
		}
		else
		{
			r+=(t1-start);
			start=t1;
    		t1+=b;
		}
	}
	if(a<b)
	{
		r+=_lcm-start;
	}
	else
	{
		l+=_lcm-start;
	}
	//cout<<l<<' '<<r<<endl;
	if(l>r)
	{
		cout<<"Dasha";
	}
	else if(l<r)
	{
		cout<<"Masha";
	}
	else
	{
		cout<<"Equal";
	}
	
    return 0;
}
