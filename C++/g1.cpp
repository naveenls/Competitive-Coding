#include<bits/stdc++.h>
using namespace std;

long long power(long long x,long long y)
{
	long long res=1;
	while(y--)
	{
		res*=2;
	}
	return res;
}

int countBits(long long n) 
{ 
   int count = 0; 
   while (n) 
   { 
        count++; 
        n >>= 1; 
    } 
    return count; 
} 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long N;
		cin>>N;
		int bits=countBits(N);
		if(power(2,bits-1)==N)
		{
			cout<<-1<<endl;
			continue;
		}
		long long odd=N-N/2;
		long long cost=odd-1;
		long long initial=power(2,bits-1);
		long long sub=0;
		while(initial>1)
		{
			long long temp=N/initial;
			cost+=(initial)*(temp-sub);
			sub=temp;
			initial/=2;
		}
		
		cout<<cost<<endl;
	}
	
	return 0;
}
