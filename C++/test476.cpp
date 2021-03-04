#include<bits/stdc++.h>
using namespace std;

const int maxX=100;
int x;

int cnt[11]={0};

long long power(long long p, long long q) 
{ 
    if (q == 0) 
        return 1; 
    long long po = power(p, q/2) % x; 
    po = (po * po) % x; 
  
    return (q%2 == 0)? po : (p * po) % x; 
} 

long long mod=1e9+7;

void fast_expo(long long res[],int q)
{
	if(q==1)
	{
		for(int i=1;i<=10;i++)
		{
			res[i%x]+=cnt[i];
	 }
	}
	else
	{
		if(q%2==0)
		{
			int p=q/2;
			
			long long temp[x]={0};
			fast_expo(temp,p);
			
			long long val=power(10,p);
			
			for(int i=0;i<x;i++)
			{
				for(int j=0;j<x;j++)
				{
					long long ind=(val*i+j)%x;
					
					res[ind]=(res[ind]+temp[i]*temp[j]%mod)%mod;	
				}
			}
		}
		else
		{
			long long temp[x]={0};
			long long temp1[x]={0};
			
			fast_expo(temp,q-1);
			fast_expo(temp1,1);
			
			long long val=10%x;
			
			for(int i=0;i<x;i++)
			{
				for(int j=0;j<x;j++)
				{
					long long ind=(val*i+j)%x;
					
					res[ind]=(res[ind]+temp[i]*temp1[j]%mod)%mod;	
				}
			}
		}
	}
}

int main()
{
	int n,b,k;
	cin>>n>>b>>k>>x;
	
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		
		cnt[a]++;
	}
	
	long long res[x]={0};
	
	fast_expo(res,b);
	
	cout<<res[k]<<endl;
	return 0;
}
