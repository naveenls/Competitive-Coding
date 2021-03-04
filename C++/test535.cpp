#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	string s;
	
	long long arr[n];
	
	long double prod=1e10;

	map<pair<int,int>,long long> mp;
	
	for(int i=0;i<n;i++)
	{
		cin>>s;
		
		bool flag=0;
		arr[i]=0;	
		int cnt=0;
		
		for(int j=0;j<s.size();j++)
		{
			if(flag)
			{
				cnt++;
				arr[i]=arr[i]*10+s[j]-'0';		
			}
			else
			{
				if(s[j]=='.')
				{
					flag=1;
				}
				else
				{
					arr[i]=arr[i]*10+s[j]-'0';
				}
			}
		}
		
			while(cnt<9)
			{
				arr[i]*=10;
				cnt++;
			}
						
			int c1=0,c2=0;
			
			while(arr[i]%2==0)
			{
				c1++;
				arr[i]/=2;
			}
			
			while(arr[i]%5==0)
			{
				c2++;
				arr[i]/=5;	
			}
						
			mp[{c1,c2}]++;
	}
	
	vector<pair<pair<int,int>,long long> > v(mp.begin(),mp.end());
	
	long long ans=0;
	
	for(int i=0;i<v.size();i++)
	{
		int a=v[i].first.first;
		int b=v[i].first.second;
		
		long long cnt=v[i].second;
		
		if(2*a>=18 && 2*b>=18)
		{
			ans+=(cnt)*(cnt-1)/2;
		}
				
		for(int j=i+1;j<v.size();j++)
		{
			int a1=v[j].first.first;
			int b1=v[j].first.second;
		
			long long cnt1=v[j].second;
						
			if(a+a1>=18 && b+b1>=18)
			{
				ans+=cnt*cnt1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
