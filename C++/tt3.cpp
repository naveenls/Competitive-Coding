#include<bits/stdc++.h>
using namespace std;

int cnt_bits(long long a)
{
	int cnt=0;
	while(a)
	{
		a/=2;
		cnt++;
	}
	return cnt;
}

long long power(int i)
{
	long long res=1;
	while(i--)
		res*=2;
	return res;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		
		int bis=cnt_bits(n);
		
		long long start=power(bis-1);
		
		long long sub=0;
		long long ans=0;
		while(start)
		{
			long long cnt=n/start;
			
			ans=(ans+(cnt-sub)*(long long)bis);
			sub=cnt;
			
			start/=2;
			bis--;
		}
		cout<<ans<<endl;
	}
	return 0;
	
}
