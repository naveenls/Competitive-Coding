#include<bits/stdc++.h>
using namespace std;

int main()
{
    
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin>>n>>m;
		long long p=n*(n-1)/2;
		long long temp2=((m-1)*(2*n-m))/2;
		long long temp=max((long long)0,p-temp2);
		long long t=n-m+1;
		cout<<(temp+t-1)/(t)<<endl;
	}
	return 0;
}
