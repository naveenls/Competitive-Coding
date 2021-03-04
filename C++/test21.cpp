#include<iostream>
using namespace std;

long long gcd(long long a, long long b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 

int main()
{
	long long n;
	cin>>n;
	if(n==1 || n==2)
	{
		cout<<n<<endl;
	}
	else
	{
		if(n%2)
		{
			cout<<n*(n-1)*(n-2)<<endl;
		}
		else
		{
			long long ans=(n*(n-1)*(n-2))/gcd(n,n-2);
			for(int i=n-3;i>=1;i-=2)
			{
				ans=max(ans,(n*(n-1)*(i))/gcd(n,i));
			}
			cout<<max(ans,(n-1)*(n-2)*(n-3))<<endl;
		}
	}
	return 0;
}
