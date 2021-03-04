#include<bits/stdc++.h>
using namespace std;

map<pair<int,int> ,long long > mp;

long long prime[10]={2,3,5,7,11,13,17,19,23,29};

long long power(long long p, long long q) 
{ 
    if (q == 0) 
        return 1; 
    long long po = power(p, q/2); 
    po = (po * po); 

    return (q%2 == 0)? po : (p * po); 
} 

long long find_min(int n,int k)
{
	if(n==1 && k==0)
		return 1;
		
	if(n==1 && k)
		return 1e18;
		
	if(mp.find({n,k})!=mp.end())
		return mp[{n,k}];
		
	long long ans=1e18;
	
	long long p=prime[k-1];
	long long mx=log((long long)1e18)/log(p);
	
	//cout<<p<<' '<<mx<<endl;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			long long val=i-1;
			if(mx>=val)
			{
				long long value=power(p,val);
				long long mi=find_min(n/i,k-1);
				
				//cout<<value<<' '<<mi<<endl;
				if(log10(value)+log10(mi)<=18)
				{
					ans=min(ans,mi*value);	
				}
			}	
		}
	}
	
	mp[{n,k}]=ans;
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	long long mi=1e18;
	
	for(int i=1;i<=10;i++)
	{
		mi=min(mi,find_min(n,i));
	}
	cout<<mi<<endl;
	
	return 0;
}

