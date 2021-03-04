#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+1;
long long m=998244353;

long long arr[maxN];

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

int getFirstSetBitPos(int n) 
{ 
    return log2(n & -n) + 1; 
} 

void solve()
{
	for(int i=1;i<maxN;i++)
	{
		int t=getFirstSetBitPos(i)-1;
		t=(1<<t);
		
		arr[i]=power((long long)i,(long long) t);
		arr[i]=(arr[i-1]+arr[i])%m;
	}
}
int main()
{
	int t;
	cin>>t;
	solve();
	while(t--)
	{
		int n;
		cin>>n;
		cout<<arr[n]<<endl;
	}
	return 0;
}
