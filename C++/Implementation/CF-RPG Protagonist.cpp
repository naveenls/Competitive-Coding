#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long p,f;
		cin>>p>>f;
		
		long long cnts,cntw;
		cin>>cnts>>cntw;
		
		long long s,w;
		cin>>s>>w;
		
		if(s>w)
		{
			swap(s,w);
			swap(cnts,cntw);
		}
		
		long long max_val=0;
		
		for(long long i=0;i<=cnts;i++)
		{
			long long c1=min(i,p/s);
			long long c2=min(cnts-i,f/s);
			
			long long cnt1=(p-c1*s)/w;
			long long cnt2=(f-c2*s)/w;
			
			long long t_cnt=min(cntw,cnt1+cnt2);
			
			max_val=max(max_val,c1+c2+t_cnt);
		}
		
		cout<<max_val<<endl;
	}
	return 0;
}
