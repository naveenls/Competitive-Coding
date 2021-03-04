#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long ts;
		cin>>ts;
		
		long long temp=ts;
		int cnt=0;
		while(ts%2==0)
		{
			ts/=2;
			cnt++;
		}
		
		long long res=1;
		
		for(int i=0;i<=cnt;i++)
		{
			res*=2;
		}
		
		cout<<temp/res<<endl;
	}
	return 0;
}
