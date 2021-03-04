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


vector<int> z_function(string s) 
{
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

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
		long long DP[s.size()];
		
		for(int i=0;i<26;i++)
		{
			cin>>val[i];
		}
		DP[0]=val[s[0]-'a'];
		
		for(int i=1;i<s.size();i++)
		{
			DP[i]=(val[s[i]-'a']+DP[i-1])%mod;
		}
	
		int n=s.size();

		long long num=0;
		
		for(int i=0;i<n;i++)
		{
			string temp=s.substr(i);
			vector<int> z_str=z_function(temp);
			
			for(int j=i+1;j<n;j++)
			{
				long long len=z_str[j-i]+1;
						
				num+=(DP[j-1]- (i?DP[i-1]:0))*len%mod;
				num%=mod;
			}
			num+=(DP[n-1]- (i?DP[i-1]:0)) %mod;
			num%=mod;
		}
		
		long long denom=n*(n+1)/2;
		denom%=mod;
		
		cout<<num*modInverse(denom,mod)%mod<<endl;		
	}
}
