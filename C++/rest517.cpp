#include<bits/stdc++.h>
using namespace std;

long long p=1e9+7;

const int maxN=5e5;
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

long long nCr(long long n,long long r)
{
	if (r==0) 
      return 1; 
      
	return (fac[n]* modInverse(fac[r]) % p * 
            modInverse(fac[n-r]) % p) % p; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	
	nCrModPFermat(maxN);
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int cnt[n]={0};
		
		int tt;
		
		for(int i=0;i<n;i++)
		{
			cin>>tt,tt--;
			cnt[tt]++;
		}
		
		if(n<=5000)
		{
			long long arr[n][n+1];
			for(int i=0;i<n;i++)
			{
				arr[i][0]=1;	
			}
			
			for(int i=0;i<n;i++)
			{
				for(int j=1;j<=cnt[i];j++)
				{
					arr[i][j]=(arr[i][j-1]+nCr(cnt[i],j))%p;
				}
				
				for(int j=cnt[i]+1;j<=n;j++)
				{
					arr[i][j]=arr[i][j-1];
				}
			}
			/*
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					cout<<arr[i][j]<<' ';
				}
				cout<<endl;
			}*/
			
			long long arr1[n][n+1];
			
			for(int j=0;j<=n;j++)
				arr1[n-1][j]=arr[n-1][j];
				
			for(int i=n-2;i>=0;i--)
			{
				for(int j=0;j<=n;j++)
				{
					arr1[i][j]=(arr1[i+1][j]*arr[i][j])%p;
				}
			}
			
			for(int i=1;i<n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					arr[i][j]=(arr[i-1][j]*arr[i][j])%p;
				}
			}
			
			long long ans[n]={0};
			
			for(int i=0;i<n;i++)
			{
				for(int j=1;j<=cnt[i];j++)
				{
					long long prod=1;
					
					if(i)
					{
						prod=(prod*arr[i-1][j-1])%p;
					}
					if(i<n-1)
					{
						prod=(prod*arr1[i+1][j])%p;
					}
					
					ans[i]=(ans[i]+prod*nCr(cnt[i],j)%p)%p;
				}
			}
			
			for(int i=0;i<n;i++)
				cout<<ans[i]<<' ';
				
			cout<<endl;
		}
		else
		{
			int ma=0;
			for(int i=0;i<n;i++)
			{
				ma=max(ma,cnt[i]);
			}
			
			if(ma==1)
			{
				long long ans[n]={0};
				long long prod=1;
				
				for(int i=n-1;i>=0;i--)
				{
					ans[i]=prod;
					prod=(prod*2)%p;
				}
				
				for(int i=0;i<n;i++)
					cout<<ans[i]<<' ';
					
				cout<<endl;
			}
			else
			{
				cout<<"Hello"<<endl;
			}
		}
	}
	
	return 0;
}
