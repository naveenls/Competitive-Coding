#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		string s;
		cin>>s;
		
		int cnt[26]={0};
		for(int i=0;i<n;i++)
		{
			cnt[s[i]-'a']++;
		}
		
		int ma=0;
		for(int i=1;i<=n;i++)
		{
			int num_groups=__gcd(i,k);
			
			int size=i/num_groups;
			
			int start=0;
			bool flag=0;
			
			int temp[26];
			for(int i=0;i<26;i++)
				temp[i]=cnt[i];
						
			for(int j=0;j<num_groups;j++)
			{
				while(start<26 && temp[start]<size)
				{
					start++;
				}
				if(start==26)
				{
					flag=1;
					break;
				}
				temp[start]-=size;
			}
			
			if(!flag)
				ma=i;
		}
		cout<<ma<<endl;
	}	
}
