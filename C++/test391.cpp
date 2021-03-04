#include<bits/stdc++.h>
using namespace std;

long long m=998244353;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long n;
		cin>>n;
		
		long long x;
		cin>>x;
		
		long long arr[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];	
		}
		long long A=arr[0];
		
		long long sum=0;
		
		long long ans=1;
		
		for(int i=0;i<n;i++)
		{
			sum=(sum*x%m + A)%m;
			ans=(ans*power(sum,n-i))%m;
		}
		
		cout<<(ans*ans)%m<<endl;
	}
	return 0;
}
