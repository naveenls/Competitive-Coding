#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

long long sum(long long n)
{
	long long ss=0;
	int flag=1;
	
	long long count_odd=0;
	long long count_even=0;
	
	long long pow=1;
	long long t_num=0;
	
	while(t_num<n)
	{
		if(flag==1)
		{
			count_odd+=pow;
			flag=0;
		}
		else
		{
			count_even+=pow;
			flag=1;
		}
		
		t_num+=pow;
		pow*=2;	
	}
	
	if(t_num>n)
	{
		pow=pow/2;
		t_num-=pow;
		
		if(flag==0)
		{
			count_odd-=pow;
			count_odd+=(n-t_num);
		}
		else
		{
			count_even-=pow;
			count_even+=(n-t_num);
		}
	}	
	count_odd%=mod;
	count_even%=mod;
	
	long long ans=(count_odd*count_odd)%mod + count_even*(count_even+1)%mod;
	return ans%mod;
	
}
int main()
{
	long long l,r;
	cin>>l>>r;
	
	cout<<(sum(r)-sum(l-1)+3*mod)%mod<<endl;
	return 0;
}
