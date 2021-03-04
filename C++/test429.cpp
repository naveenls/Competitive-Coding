#include<bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long m) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}

long long modInverse(long long a, long long m) 
{ 
    return power(a, m-2, m);
} 

long long mod=998244353;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		
		long long val[26];
		
		for(int i=0;i<26;i++)
		{
			cin>>val[i];
		}
		
		int n=s.size();
		
		long long num=0;
		
		for(int i=0;i<n;i++)
		{
			long long sum=val[s[i]-'a'];
			
			int len=1;
			int eq_len=1;
			bool flag=0;
			
			num=(num+sum)%mod;
			
			for(int j=i+1;j<n;j++)
			{
				while(s[j]!=s[i+(j-i)%len])
				{
					sum+=val[s[i+len]-'a'];
					
					if(!flag)
					{
						if(s[i+len-1]==s[i+len])
						{
							eq_len++;
						}
						else
						{
							flag=1;
						}
					}
					
					len++;
				}
				
				long long ss=0;
				
				long long temp=(j-i+1)/len;
				long long tt=(temp)*(temp+1)/2;
				tt%=mod;
				
				ss=(ss+tt*sum%mod)%mod;
				
				long long temp1=temp*len;
				int rem_len=j-i+1-temp1;
				
				if(eq_len>=rem_len)
				{
					long long aa=rem_len*(rem_len+1)/2;
					aa%=mod;
					
					aa=(aa*val[s[j]-'a'])%mod;
					
					ss=(ss+aa+rem_len*temp%mod*sum%mod)%mod;	
				}
				num=(num+ss)%mod;
			}
		}
		long long denom=n*(n+1)/2;
		denom%=mod;
		cout<<num<<endl;
		
		cout<<num*modInverse(denom,mod)%mod<<endl;
		
	}
	
	
}
