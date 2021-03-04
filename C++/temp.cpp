#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    long long x;
    cin>>n>>x;
    
   	int DP[n+1][n+1][n];
    int a[n+1];
    
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    
    long long ans = 1e18;
    
    for(int mod=1;mod<=n;mod++)
    {
    	for(int i=0;i<=n;i++)
	    	for(int j=0;j<=mod;j++)
	    		for(int k=0;k<mod;k++)
	    			DP[i][j][k] = -2e9;
			
		DP[0][0][0] = 0;
		
		for(int i=1;i<=n;i++)
	    {
			for(int j=1;j<=mod;j++)
			{
				for(int k=0;k<mod;k++)
				{
					int t = (k - a[i]%mod + mod)%mod;
					
					DP[i][j][k] = max(DP[i-1][j][k], DP[i-1][j-1][t] + a[i]);	
				}	
			}    	
		}
		
		//cout<<DP[n][mod][x%mod]<<endl;
		
		if(DP[n][mod][x%mod] > 0)
			ans = min(ans, (x - DP[n][mod][x%mod])/mod);
	}
    
	cout<<ans<<endl;

	return 0;
}
