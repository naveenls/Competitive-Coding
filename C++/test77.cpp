#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h> 
using namespace std; 
  
long long p=1e9+7;

const int maxN=1000;
long long fac[maxN+1]; 

long long power(long long x, long long y) 
{ 
    long long res = 1; 
  
    x = x % p;  
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
  
long long modInverse(long long n) 
{ 
    return power(n, p-2); 
} 

void nCrModPFermat(long long n) 
{    
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p;   
} 

long long nCr(long long n,vector<int> &val)
{
	long long res=fac[n];
	
	for(int i=0;i<val.size();i++)
	{
		//cout<<val[i]<<endl;
		res=(res*modInverse(fac[val[i]]))%p;
	}
      
	return res;
}
int main()
{
	
	int n,m;
	cin>>n>>m;
	vector<int> v(m);
	nCrModPFermat(n);
	
	for(int i=0;i<m;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	vector<int> values;
	int in=0;
	for(int i=0;i<m;i++)
	{
		values.push_back(v[i]-in-1);
		in=v[i];
	}
	values.push_back(n-in);
	long long ans=nCr(n-m,values);
	for(int i=1;i<values.size()-1;i++)
	{
		ans=(ans*power(2,values[i]-1))%p;
	}
	cout<<ans<<endl;
	return 0;
}
