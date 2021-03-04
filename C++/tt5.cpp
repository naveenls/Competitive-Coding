#include<bits/stdc++.h>
using namespace std;

long long m=1000000007;

long long power(long long x, long long y) 
{ 
    if (y == 0)
        return 1; 
    long long p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,p;
		cin>>n>>p;
		
		int arr[n];
		int k;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
    
		vector<int> s1;
		vector<int> s2;
		
		sort(arr,arr+n,greater<int> ());
	    
	    if(p==1)
	    {
	        if(n%2==0)
	        {
	            cout<<0<<endl;
	        }
	        else
	        {
	            cout<<1<<endl;
	        }
	        continue;
	    }
		int flag=0;
		int last_power=-1;
		
		map<int,int> mp;
		
		for(int i=0;i<n;i++)
		{
			if(last_power==-1)
			{
				if(flag==0)
				{
					s1.push_back(arr[i]);
					flag=1;
				}
				else
				{
					s2.push_back(arr[i]);
					flag=0;
				}
				last_power=arr[i];
			}
			else
			{
				if(flag==0)
				{
					s1.push_back(arr[i]);
				}
				else
				{
					s2.push_back(arr[i]);
				}
				
				mp[arr[i]]++;
				int start=arr[i];
				
				while(mp.find(start)!=mp.end() && mp[start]==p)
				{
				    //cout<<mp[start]<<endl;
					mp[start]=0;
					mp[start+1]++;
					start++;
					//cout<<start<<endl;
				}
				if(start==last_power)
				{
					mp[start]=0;
					
					last_power=-1;
					flag=0;	
				}
			}
		}
		long long sum1=0;
		for(auto ele:s1)
		{
			sum1=(sum1+power((long long)p,(long long)ele))%m;
		}
		
		long long sum2=0;
		for(auto ele:s2)
		{
			sum2=(sum2+power((long long)p,(long long)ele))%m;
		}
		cout<<(sum1-sum2+m)%m<<endl;
	}
	return 0;
	
}
