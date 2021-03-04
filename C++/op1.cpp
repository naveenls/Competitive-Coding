#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,n;
		cin>>a>>b>>n;
		
		long long s1=0;
		long long s2=1;
		
		if(a<b)
			swap(a,b);
		
		int cnt=0;
		
		while(s1*b + s2*a<=n)
		{
			long long temp=s1;
			s1=s2;
			s2+=temp;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
