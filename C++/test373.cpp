#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		map<int,int> mp;
		
		int m;
		cin>>m;
		
		int p,s;
		for(int i=0;i<m;i++)
		{
			cin>>p>>s;
			mp[p]=max(mp[p],s);
		}
		
		int ma=0;
		for(auto itr=mp.rbegin();itr!=mp.rend();itr++)
		{
			ma=max(ma,itr->second);
			
			itr->second=ma;
		}
		
		int cnt=0;
		ma=0;
		int prev=-1;
		
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			ma=max(ma,arr[i]);

			auto itr=mp.lower_bound(ma);
			if(itr==mp.end())
			{
				cout<<-1<<endl;
				flag=1;
				break;
			}
			
			int temp=itr->second;
			
			if(temp<i-prev)
			{
				cnt++;
				prev=i-1;
				ma=arr[i];
			}
		}
		cnt++;
		if(!flag)
		{
			cout<<cnt<<endl;
		}
		
	}
	return 0;
}
