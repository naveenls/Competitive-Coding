#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s,p;
		cin>>s>>p;
		
		char arr[26]={0};
		
		for(int i=0;i<s.size();i++)
			arr[s[i]-'a']++;
			
		for(int i=0;i<p.size();i++)
			arr[p[i]-'a']--;
			
		vector<string> val(26,"");
		
		for(int i=0;i<26;i++)
		{
			while(arr[i]--)
			{
				val[i].push_back(i+'a');
			}
		}
		
		bool flag=0;
		
		for(int i=0;i<p.size()-1;i++)
		{
			if(p[i]<p[i+1])
			{
				flag=1;
				break;
			}
			
			if(p[i]>p[i+1])
			{
				flag=0;
				break;
			}
		}
		
		string ans="";
		
		for(int i=0;i<26;i++)
		{
			if(i<p[0]-'a' || i>p[0]-'a')
			{
				ans+=val[i];
			}
			else
			{
				if(flag)
				{
					ans+=val[i];
					ans+=p;
				}
				else
				{
					ans+=p;
					ans+=val[i];
				}
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
