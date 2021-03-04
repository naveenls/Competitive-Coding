#include<bits/stdc++.h>
using namespace std;

long long k;
int n,m;

const int maxN=1e5;

long long arr[maxN+5][5];

bool check(int len)
{
	if(len==0)
		return true;
		
	int K = n - len + 1;
	
	long long LR[n+1][m];
	
	for(int j=0;j<m;j++)
	{
	    LR[0][j]=0;
	    
		for(int i = 1; i <= n; i++)
		{
	        if(i % len == 1)
	            LR[i][j] = arr[i][j];
	        else
	            LR[i][j] = max(LR[i - 1][j], arr[i][j]);        
	    }	
	}
    
	
	long long RL[n+1][m];
	
	for(int j=0;j<m;j++)
	{
		for(int i = n; i >= 1; i--)
		{
	        if(i == n) 
	            RL[i][j] = arr[i][j]; 
	        else if(i % len == 0)
	            RL[i][j] = arr[i][j];
	        else
	            RL[i][j] = max(RL[i+1][j], arr[i][j]);
    	}
	}
    
    long long sum;
    for(int i = 1; i <= K; i++)
    {
    	sum=0;
    	for(int j=0;j<m;j++)
    	{
    		sum+=max(RL[i][j], LR[i + len - 1][j]);
		}
	//	cout<<sum<<' '<<len<<endl;
		if(sum<=k)
			return true;
	}
	return false;
}

void print_ans(int len)
{
	if(len==0)
	{
		for(int i=0;i<m;i++)
		{
			cout<<0<<' ';
		}
		return;
	}
		
	int K = n - len + 1;
	
	long long LR[n+1][m];
	
	for(int j=0;j<m;j++)
	{
	    LR[0][j]=0;
		for(int i = 1; i <= n; i++)
		{
	        if(i % len == 1)
	            LR[i][j] = arr[i][j];
	        else
	            LR[i][j] = max(LR[i - 1][j], arr[i][j]);        
	    }	
	}
    
	
	long long RL[n+1][m];
	
	for(int j=0;j<m;j++)
	{
		for(int i = n; i >= 1; i--)
		{
	        if(i == n) 
	            RL[i][j] = arr[i][j]; 
	        else if(i % len == 0)
	            RL[i][j] = arr[i][j];
	        else
	            RL[i][j] = max(RL[i+1][j], arr[i][j]);
    	}
	}
    
    long long sum;
    long long temp[m];
    
    for(int i = 1; i <= K; i++)
    {
    	sum=0;
    	for(int j=0;j<m;j++)
    	{
    		sum+=max(RL[i][j], LR[i + len - 1][j]);
    		temp[j]=max(RL[i][j], LR[i + len - 1][j]);
		}
		if(sum<=k)
		{
			for(int j=0;j<m;j++)
			{
				cout<<temp[j]<<' ';
			}
			return;
		}
	}
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	int l=0,r=n;
	
	int ans=0;
	
	while(l<=r)
	{
		int mid=(l+r)/2;
		
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	print_ans(ans);
	return 0;
}
