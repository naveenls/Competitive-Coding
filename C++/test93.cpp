#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5+1;
multiset<long long> s[maxN];
void prime_factorize(long long a)
{
	if(a!=1)
	{
	    //cout<<a<<endl;
		long long cnt=0;
		while(a%2==0)
		{
			a/=2;
			cnt++;
		}
		s[2].insert(cnt);
		
		for(long long i=3;i<=sqrt(a);i++)
		{
			if(a%i==0)
			{
				cnt=0;
				while(a%i==0)
				{
					a/=i;
					cnt++;
				}
				//cout<<i<<endl;
				s[i].insert(cnt);
			}
		}
		if(a>1)
		{
		   // cout<<a<<endl;
			s[a].insert(1);
		}
	}
}
long long power(long long a,long long b)
{
    long long res=1;
    while(b--)
    {
        res*=a;
    }
    return res;
}

int main()
{
	int n;
	cin>>n;
	
	long long a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		prime_factorize(a);
	}
	
	long long res=1;
	for(int i=2;i<maxN;i++)
	{
		auto itr=s[i].begin();
		
		if(s[i].size()==n)
		{
			itr++;
			res=res*(power(i,*itr));
		}
		else if(s[i].size()==n-1)
		{
			res=res*(power(i,*itr));
		}
	}
	cout<<res<<endl;
	return 0;
}
