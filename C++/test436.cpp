#include<bits/stdc++.h>
using namespace std;

long long find_val(string s,long long mod)
{
	long long p=1;
	
	long long ans=0;
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			ans=(ans+p)%mod;	
		}
		p=(p*2)%mod;
	}
	
	return ans;
}

int find_step(long long n)
{
	if(n==0)
		return 0;
		
	long long bits=__builtin_popcount(n);
	
	return 1+find_step(n%bits);
}

int main()
{
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	long long cnt=0;
	
	for(int i=0;i<n;i++)
	{
		cnt+=(s[i]=='1');
	}
	
	reverse(s.begin(),s.end());
	
	long long val1=-1,val2;
	
	if(cnt>1)
	{
		val1=find_val(s,cnt-1);
	}
	
	val2=find_val(s,cnt+1);
	
	long long p1=1;
	long long p2=1;
	
	int ans[n];
	
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			if(cnt>1)
			{
				long long temp=(val1-p1+ (cnt-1) )%(cnt-1);								
				ans[n-i-1]=1+find_step(temp);
			}
			else
			{
				ans[n-i-1]=0;
			}
		}
		else
		{
			long long temp=(val2+p2)%(cnt+1);			
			ans[n-i-1]=1+find_step(temp);
		}
		
		if(cnt>1)
		{
			p1=(2*p1)%(cnt-1);
		}
		
		p2=(2*p2)%(cnt+1);
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<endl;
	}
}
