#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    long long m;
    cin>>n>>m;
    
    long long arr[50]={0};
    
    long long a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        
        for(int j=0;j<50;j++)
        {
            arr[j]+=a%2;
            a/=2;
        }
    }
    
    long long min_sum=0;
    
    long long N=n;
    
    bool set_bit[50]={0};
    
    for(long long i=0;i<50;i++)
    {
        if(arr[i]>=N-arr[i])
        {
            min_sum+=(N-arr[i])*(1LL<<i);
            set_bit[i]=1;
        }
        else
        {
            min_sum+=(arr[i])*(1LL<<i);
            set_bit[i]=0;
        }
    }
    
    if(min_sum>m)
    {
        cout<<-1<<endl;
    }
    else
    {
        for(int i=49;i>=0;i--)
        {
            long long cost=0;
            
            if(arr[i]<N-arr[i])
            {
                cost=(N-2*arr[i])*(1LL<<i);
                
                if(cost+min_sum<=m)
                {
                    min_sum+=cost;
                    set_bit[i]=1;
                }
            }
        }
        
        long long val=1;
        long long ans=0;

        for(int i=0;i<50;i++)
        {
            if(set_bit[i])
                ans+=val;
                
            val*=2;
        }
        
        cout<<ans<<endl;
        
    }
    
}
int main() {
	
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
	    cout<<"Case #"<<i<<": ";
	    solve();
	}
	return 0;
}

