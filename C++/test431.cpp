#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+1;

long long cnt[maxN]={0};

long long calc_triples()
{
	bool is_prime[maxN];
	int mu[maxN];
	
	for(int i=1;i<=maxN;i++)
	{
		is_prime[i]=1;
	}
	
	mu[1]=1;
	
	for(int i=2;i<maxN;i++)
	{
		if(is_prime[i])
		{
			for(int j=i;j<maxN;j+=i)
			{
				if(j>i)
				{
					is_prime[j]=0;	
				}
				 
				if(j%(i*i)==0)
				{
					mu[j]=0;
				}
				mu[j]=-mu[j];
			}
		}
	}
	
	long long val[maxN]={0};
	
	for(int i=1;i<maxN;i++)
	{
		for(int j=i;j<maxN;j+=i)
		{
			val[i]+=cnt[j];
		}
	}
	
	long long ans=0;
	for(int d=1;d<maxN;d++)
	{
		ans+=mu[d]*val[d]*(val[d]-1)*(val[d]-2)/2;
	}
	
	return ans;
}
int main()
{
	int n;
	cin>>n;
	
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cnt[a]++;
	}
	
	cout<<calc_triples();
	return 0;
}
