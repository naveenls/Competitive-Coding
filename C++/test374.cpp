#include<bits/stdc++.h>
using namespace std;

long long mod=1e15+7;

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int top[n];
	int bot[n];
	
	int mask=(1<<15)-1;
	int mask1=(1<<30)-1;
	mask1^=mask;
	
	for(int i=0;i<n;i++)
	{
		bot[i]=mask & arr[i];
		top[i]=mask1 & arr[i];
		top[i]=(top[i]>>15);
	}
	
	map<long long,int> mp;
	
	for(int i=0;i<mask;i++)
	{
		long long val[n];
		
		long long mi=30;
		
		for(int j=0;j<n;j++)
		{
			val[j]=0;
			
			int temp=bot[j]^i;
			
			while(temp)
			{
				val[j]+=temp%2;
				temp/=2;
			}
			mi=min(mi,val[j]);
		}
		
		long long tt=0;
		long long mul=1;
		
		for(int j=0;j<n;j++)
		{
			val[j]-=mi;
			
			tt=(tt+mul*val[j]%mod)%mod;
			mul=(mul*16)%mod;
		}
		mp[tt]=i;
	}
	
	for(int i=0;i<mask;i++)
	{
		long long val[n];
		long long ma=0;
		
		for(int j=0;j<n;j++)
		{
			val[j]=0;
			
			int temp=top[j]^i;
			
			while(temp)
			{
				val[j]+=temp%2;
				temp/=2;
			}
			ma=max(ma,val[j]);
		}
		
		long long tt=0;
		long long mul=1;
		
		for(int j=0;j<n;j++)
		{
			val[j]=ma-val[j];
			
			tt=(tt+mul*val[j]%mod)%mod;
			mul=(mul*16)%mod;
		}
		
		if(mp.find(tt)!=mp.end())
		{
			int temp=i<<15;
			cout<<(temp|mp[tt])<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}
