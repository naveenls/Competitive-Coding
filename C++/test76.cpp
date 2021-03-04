#include<bits/stdc++.h>
using namespace std;

long long m=10;

int power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    int p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

int main()
{
    
	int t;
	cin>>t;
	while(t--)
	{
		long long k,d0,d1;
		cin>>k>>d0>>d1;
		long long p=(power(2,k)-1+10)%10;
		p=(p*(d0+d1))%10;
		if(p%3==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
