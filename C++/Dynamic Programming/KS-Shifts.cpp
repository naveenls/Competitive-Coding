#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    long long h;
    cin>>n>>h;
    
    long long a[n],b[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    for(int i=0;i<n;i++)
        cin>>b[i];
        
    int max_val=(1<<n);
    
    long long DPa[max_val]={0};
    long long DPb[max_val]={0};
    
    for(int i=0;i<max_val;i++)
    {
        long long sum=0;
        
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                sum+=a[j];
            }
        }
        
        if(sum>=h)
        {
            DPa[i]++;
        }
    }
    
    for(int i=0;i<max_val;i++)
    {
        long long sum=0;
        
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                sum+=b[j];
            }
        }
        
        if(sum>=h)
        {
            DPb[i]++;
        }
    }
    
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<max_val;i++)
        {
            if(i & (1<<j))
                continue;
                
            DPa[i | (1<<j)]+=DPa[i];
            DPb[i | (1<<j)]+=DPb[i];
        }
    }
    
    long long ans=DPa[max_val-1]*DPb[max_val-1];
    long long sub=0;
    
    for(int i=0;i<max_val-1;i++)
    {
        int cnt=n;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
                cnt--;
        }
        
        if(cnt%2)
        {
            sub+=DPa[i]*DPb[i];
        }
        else
        {
            sub-=DPa[i]*DPb[i];
        }
    }
    
    cout<<ans-sub<<endl;
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

