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

long long* initialize(int n)
{
	long long* bitTree=new long long[n+2];
	for(int i=0;i<=n;i++)
		bitTree[i]=1;
		
	return bitTree;
}

void update(long long * bitTree,int idx, int val,int n) 
{
    for (; idx <= n+1; idx = idx | (idx + 1))
        bitTree[idx] = (bitTree[idx]*val)%p;
}

void update_range(long long * bitTree,int l,int r,long long val,int n)
{
	update(bitTree,l,val,n);
	update(bitTree,r+1,modInverse(val),n);	
}

long long get_prod(long long * bitTree,int r)
{
	long long res=1;

	for (; r >= 0; r = (r & (r + 1)) - 1)
            res = (res*bitTree[r])%p;

    return res;
}

void reset(long long* bitTree,int n)
{
	for(int i=0;i<=n+1;i++)
	{
		bitTree[i]=1;
	}
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
		int a;
		
		for(int i=0;i<n;i++)
		{
			cin>>a,a--;
			
			cnt[a]++;	
		}
		
		vector<long long> prod[n];
		vector<long long> num_ways[n];
		
		for(int i=0;i<n;i++)
		{
			prod[i].resize(cnt[i]+1);
			num_ways[i].resize(cnt[i]+1);
			
			num_ways[i][0]=1;
			for(int j=1;j<=cnt[i];j++)
			{
				num_ways[i][j]=(num_ways[i][j-1]+nCr(cnt[i],j))%p;
			}
		}
		
		long long *BIT=initialize(n);
		
		for(int i=n-1;i>=0;i--)
		{	
			for(int j=0;j<=cnt[i];j++)
			{
				prod[i][j]=1;
				
				prod[i][j]=(prod[i][j]*get_prod(BIT,j))%p;	
			}
			
			for(int j=0;j<cnt[i];j++)
				update_range(BIT,j,j,num_ways[i][j],n);
				
			update_range(BIT,cnt[i],n,num_ways[i][cnt[i]],n);
		}
		
		reset(BIT,n);
		
		long long ans[n]={0};
		
		for(int i=n-1;i>=0;i--)
		{	
			for(int j=1;j<=cnt[i];j++)
			{
				prod[i][j]=(prod[i][j]*get_prod(BIT,j-1))%p;	
			}
			
			for(int j=0;j<cnt[i];j++)
				update_range(BIT,j,j,num_ways[i][j],n);
				
			update_range(BIT,cnt[i],n,num_ways[i][cnt[i]],n);
			
			for(int j=1;j<=cnt[i];j++)
			{
				ans[i]=(ans[i]+prod[i][j]*num_ways[i][j]%p)%p;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}
