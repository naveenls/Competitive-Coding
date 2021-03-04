#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) c.begin(),c.end()

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		
		int ans[n];
		
		set<int> v1,v2;
		
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
				v1.insert(i);
			else
				v2.insert(i);
		}
		
		int cnt=0;
		while(v1.size() && v2.size())
		{
			cnt++;
			
			bool flag=0;
			
			if(*v1.begin()>*v2.begin())
				flag=1;
				
			int prev=-1;
			while(true)
			{
				if(flag==0)
				{
					auto itr=v1.upper_bound(prev);
					
					if(itr==v1.end())
					{
						break;
					}
					else
					{
						ans[*itr]=cnt;
						
						prev=*itr;
						v1.erase(itr);
						flag=1-flag;
					}
				}
				else
				{
					auto itr=v2.upper_bound(prev);
					
					if(itr==v2.end())
					{
						break;
					}
					else
					{
						ans[*itr]=cnt;
						
						prev=*itr;
						v2.erase(itr);
						flag=1-flag;
					}
				}
			}
		}
		while(v1.size())
		{
			cnt++;
			
			ans[*v1.begin()]=cnt;
			v1.erase(*v1.begin());
		}
		
		while(v2.size())
		{
			cnt++;
			
			ans[*v2.begin()]=cnt;
			v2.erase(*v2.begin());
		}
		
		cout<<cnt<<endl;
		
		for(int i=0;i<n;i++)
			cout<<ans[i]<<' ';
			
		cout<<endl;
	}
}
