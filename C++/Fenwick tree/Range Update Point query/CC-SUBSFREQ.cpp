#include<bits/stdc++.h>
using namespace std;

long long p=1e9+7;

const int maxN=5e5+10;
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
		
		int ma=0;
		
		for(int i=0;i<n;i++)
		{
			cin>>a,a--;
			
			cnt[a]++;
			if(cnt[a]>ma)
			    ma=cnt[a];
		}
		
		vector<long long> num_ways[n+1];
		
		bool flag[n+1]={0};
		for(int i=0;i<n;i++)
		{
		    flag[cnt[i]]=1;
		}
		
		long long total_product[n+2];
		long long temp_product[n+2];
		
		for(int i=0;i<n;i++)
		{
			total_product[i]=1;
			temp_product[i]=1;
			
			if(flag[i])
			{
			    num_ways[i].resize(i+1);
			    num_ways[i][0]=1;
			    
			    for(int j=1;j<=i;j++)
			    {
			        num_ways[i][j]=(num_ways[i][j-1] + nCr(i,j))%p;   
			    }
			}
		}
		
		total_product[n]=1;
		temp_product[n]=1;
		    
		if(flag[n])
		{
		    num_ways[n].resize(n+1);
		    num_ways[n][0]=1;
		    
		    for(int j=1;j<=n;j++)
		    {
                num_ways[n][j]=(num_ways[n][j-1] + nCr(n,j))%p;
               // cout<<"hi"<<endl;
		    }
		}

		for(int i=0;i<n;i++)
		{
		    for(int j=0;j<cnt[i];j++)
		    {
		        total_product[j]=(total_product[j]*num_ways[cnt[i]][j])%p;
		    }
		    temp_product[cnt[i]]=(temp_product[cnt[i]]*num_ways[cnt[i]][cnt[i]])%p;
		}
		for(int i=1;i<=n;i++)
		{
		    temp_product[i]=(temp_product[i-1]*temp_product[i])%p;
		    total_product[i]=(total_product[i]*temp_product[i])%p;
		}

		long long *BIT=initialize(ma);

		long long ans[n]={0};
		
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=cnt[i];j++)
			{
			    long long val=num_ways[cnt[i]][j]*get_prod(BIT,j)%p;
			    
				long long temp=total_product[j]*get_prod(BIT,j-1)%p*modInverse(val)%p;
			    
			    val=(num_ways[cnt[i]][j]-num_ways[cnt[i]][j-1] + p)%p;
			    
				ans[i]=(ans[i]+temp*val%p)%p;
			}
			
	        for(int j=0;j<cnt[i];j++)
	        {
	            update_range(BIT,j,j,num_ways[cnt[i]][j],ma);
	        }
			update_range(BIT,cnt[i],ma,num_ways[cnt[i]][cnt[i]],ma);
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<' ';
		}
		
		cout<<endl;
	}
	
	return 0;
}
