#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long cnt=0;
		while(n>=2)
		{
			long long temp=(-1+sqrt(1+24*n))/6;
			//cout<<temp<<endl;
			n-=((3*temp*temp+temp)/2);
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
