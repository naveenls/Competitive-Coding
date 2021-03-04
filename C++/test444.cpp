#include<bits/stdc++.h>
using namespace std;

#define MAXN   1000001 
  
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	sieve();
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		map<int,int> mp;
		
		int a;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			
			map<int,int> temp;
			
			while(a!=1)
			{
				temp[spf[a]]++;
				a/=spf[a];
			}
			
			for(auto ele:temp)
			{
				mp[ele.first]=max(mp[ele.first],ele.second);
			}
		}
		int ans=0;
		for(auto ele:mp)
		{
			ans+=ele.second;
		}
		cout<<ans<<endl;
	}
	return 0;
}
