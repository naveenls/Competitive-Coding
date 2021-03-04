#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		
		int arr[s.size()];
		
		if(s[0]=='-')
			arr[0]=-1;
		else
			arr[0]=1;
			
		for(int i=1;i<s.size();i++)
		{
			if(s[i]=='-')
				arr[i]=-1;
			else
				arr[i]=1;
				
			arr[i]+=arr[i-1];
		}
		map<int,long long> mp;
		
		for(int i=0;i<s.size();i++)
		{
			if(arr[i]<0)
			{
				if(mp.find(arr[i])==mp.end())
				{
					mp[arr[i]]=i+1;
				}
			}
		}
		
		long long ans=0;
		for(int i=0;i<=s.size();i++)
		{
			int j=-(i+1);
			if(mp.find(j)!=mp.end())
			{
				ans+=mp[j];
			}
			else
			{
				ans+=s.size();
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
