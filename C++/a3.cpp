#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,q;
		cin>>a>>b>>q;
		long long gcd_=gcd(a,b);
		
		long long ma=max(a,b);
		long long mi=min(a,b);
		long long lcm=(a*b)/gcd_;
		
		long long l,r;
		
		while(q--)
		{
			cin>>l>>r;
			long long ans=(r-l+1);
			long long k1=l/lcm;
			long long k2=r/lcm;
			
			long long count=k2-k1+1;
			if(l>k1*lcm+b-1)
			{
				count--;
			}
			else
			{
				ans+=(l-k1*lcm);
			}
			if(r>k2*lcm+b-1)
			{
				count--;
			}
			else
			{
				ans+=(k2*lcm+b-r+1);
			}
			ans-=(count)*(b-1);
			cout<<ans<<' ';
		}
		cout<<endl;
	}
	return 0;
}
