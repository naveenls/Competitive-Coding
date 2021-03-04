#include<bits/stdc++.h>
using namespace std;

long long m=1e9+7;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

void calculate_lp_string(int lps[],string s)
{
    lps[0]=0;
    int len=0;
    
    for(int i=1;i<s.size();i++)
    {
        while(len!=0 && s[i]!=s[len])
        {
            len=lps[len-1];
        }
        
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
        }
        else
        {
            lps[i]=0;
        }
    }
    
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	string p;
	cin>>p;
	
	int arr[m];
	int end[m];
	
	memset(end,-1,sizeof(end));
	for(int i=0;i<m;i++)
		cin>>arr[i],arr[i]--;
		
	char ans[n];
	for(int i=0;i<n;i++)
		ans[i]='A';
	
	int LPS[p.size()];
	calculate_lp_string(LPS,p);
	
	set<int> sizes;
	
	int temp=LPS[p.size()-1];
	
	while(temp)
	{
		sizes.insert(temp);
		
		temp=LPS[temp-1];
	}
	for(int i=0;i<m-1;i++)
	{
		if(arr[i+1]<=arr[i]+p.size()-1)
		{
			int len=arr[i]+p.size()-arr[i+1];

			if(sizes.find(len)==sizes.end())
			{
				cout<<0<<endl;
				return 0;
			}
			end[i]=arr[i+1]-1;
		}
	}
	
	for(int i=0;i<m;i++)
	{
		int start=arr[i];
		if(end[i]==-1)
			end[i]=arr[i]+p.size()-1;
		
		for(int j=start;j<=end[i];j++)
		{
			ans[j]=p[j-start];
		}
	}
	
	long long cnt=0;
	for(int i=0;i<n;i++)
		cnt+=(ans[i]=='A');
		
	cout<<power(26,cnt)<<endl;
	return 0;
}
