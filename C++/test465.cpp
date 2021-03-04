#include<bits/stdc++.h>
using namespace std;

const int maxV=70+1;

int cnt[maxV]={0};
vector<int> factors;

map<int,int> mp;

void factorize(int a)
{
	int val=0;
	
	for(int i=2;i<=a;i++)
	{
		if(a%i==0)
		{
			int cnt=0;
			
			while(a%i==0)
			{
				a/=i;
				cnt++;	
			}
			
			if(cnt%2)
			{
				val|=(1<<mp[i]);	
			}
		}	
	}
	factors.push_back(val);
}


long long DP[maxV][(1<<20)];
long long mod=1e9+7;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
} 

long long find_ans(int i,int mask)
{
	if(i==71)
	{
		if(mask==0)
			return 1;
		else
			return 0;
	}
	
	if(DP[i][mask]!=-1)
		return DP[i][mask];
	
	long long ans=0;
		
	if(cnt[i])
	{
		long long val=power(2,cnt[i]-1);
		
		ans=(ans+val*find_ans(i+1,mask^factors[i])%mod)%mod;
		ans=(ans+val*find_ans(i+1,mask)%mod)%mod;
	}
	else
	{
		ans=(ans+find_ans(i+1,mask))%mod;
	}
	DP[i][mask]=ans;
	return ans;
}

int main()
{
	int primes[]={2, 3 ,5,7,11,13,17,19,23,29 ,31 ,37 ,41, 43, 47, 53, 57, 59, 61, 67};
	
	for(int i=0;i<20;i++)
	{
		mp[primes[i]]=i;
	}
	
	int n;
	cin>>n;
	
	int a;
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cnt[a]++;
	}
	
	factors.push_back(0);
	
	for(int i=1;i<=70;i++)
	{
		factorize(i);
	}
	
	memset(DP,-1,sizeof(DP));
	
	cout<<(find_ans(1,0)-1+mod)%mod;

	return 0;
}
