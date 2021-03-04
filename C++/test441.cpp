#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5+1;
int phi[maxN]={0};

void seive()
{
	phi[1]=1;
	
	for(int i=2;i<maxN;i++)
	{
		if(phi[i]==0)
		{
			phi[i]=i-1;
			for(int j=i*i;j<maxN;j+=i)
			{
				phi[j]=i;
			}
		}
		else
		{
			int d=phi[i];
			int j=i/d;
			
			phi[i]=(j%d==0 ? d : d-1)*phi[j];
		}
	}
}

long long mod=1e9+7;

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

int main()
{
	seive();
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int k;
		cin>>k;
		
		long long a[k],b[k];
		
		int mi=2*1e5;
		
		for(int i=0;i<k;i++)
		{
			cin>>a[i]>>b[i];
			a[i]--;
			mi=min(mi,(int)b[i]);
		}
		
		long long num=0;
		
		for(int f=1;f<=mi;f++)
		{
			long long prod=phi[f];
			
			for(int i=0;i<k;i++)
			{
				prod=(prod*(b[i]/(f) - a[i]/(f))%mod)%mod;
			}
			
			num=(num+prod%mod)%mod;
		}

		num=(num+mod)%mod;
		
		long long denom=1;
		for(int i=0;i<k;i++)
		{
			denom=(denom*(b[i]-a[i])%mod)%mod;
		}

		cout<<(mod-num*modInverse(denom,mod)%mod)%mod<<endl;
	}
	return 0;
}
