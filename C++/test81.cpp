#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
} 

int main()
{
    string s;
    cin>>s;
    long long val=0;
    for(int i=0;i<s.size();i++)
    {
    	val=((val*2)+s[i]-'0')%mod;
	}
	cout<<(val*power(2,s.size()-1))%mod;
    return 0;
}
