#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	n=2+8*n;
	set<long long> u;
	for(long long i=3;i<=sqrt(n);i+=2)
	{
		u.insert(i*i);
		if(u.find(n-i*i)!=u.end())
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	
	return 0;
}
