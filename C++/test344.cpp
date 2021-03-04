#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e7+1;

int spf[MAXN]; 

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 

    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    {
        if (spf[i] == i) 
        {
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

int main()
{
	sieve();
	
	int n;
	cin>>n;
	
	long long DP[n+1];
	
	long long ans=1;
	DP[1]=1;
	
	long long ma=0;
	
	for(int i=2;i<=n;i++)
	{
		int sp=spf[i];
		int temp=i;
		
		long long cnt=0;
		
		while(temp%sp==0)
		{
			cnt++;
			temp/=sp;
		}
		
		DP[i]=DP[temp]*(cnt+1);
		
		ma=max(ma,DP[i]);
		ans+=i*DP[i];
	}

	cout<<ans<<' '<<ma<<endl;
	return 0;
}
