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
		
		string s,t;
		cin>>s>>t;
		
		int cnts[26]={0};
		int cntt[26]={0};
		
		for(int i=0;i<n;i++)
		{
			cnts[s[i]-'a']++;
			cntt[t[i]-'a']++;
		}
		
		bool flag=0;
		bool flag1=0;
		for(int i=0;i<26;i++)
		{
			if(cnts[i]!=cntt[i])
			{
				cout<<"NO"<<endl;
				flag=1;
				break;
			}
			
			if(cnts[i]>1)
				flag1=1;
		}
		
		if(flag)
			continue;
			
		if(flag1)
		{
			cout<<"YES"<<endl;
			continue;
		}
		
		int s1=0;
		int s2=0;
		
		for(int i=0;i<n;i++)
		{
			int t1=0;
			int t2=0;
			
			for(int j=0;j<i;j++)
			{
				if(s[j]>s[i])
					t1++;
					
				if(t[j]>t[i])
					t2++;
			} 
			s1+=t1;
			s2+=t2;
		}
		
		if(abs(s1-s2)%2)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
		
	return 0;
}
