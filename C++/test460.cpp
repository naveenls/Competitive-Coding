#include<bits/stdc++.h>
using namespace std;

int occurence(string temp)
{
	string s="abacaba";
	
	int cnt=0;
	for(int i=0;i<=temp.size()-7;i++)
	{
		string ss=temp.substr(i,7);
		
		if(ss==s)
		{
			cnt++;
		}
	}
	return cnt;
}

string check(string temp)
{
	string s="abacaba";
	
	for(int i=0;i<=temp.size()-7;i++)
	{
		bool flag=0;
		
		for(int j=0;j<7;j++)
		{
			if(temp[i+j]!='?' && temp[i+j]!=s[j])
			{
				flag=1;
				break;
			}
		}
		
		if(!flag)
		{
			string t_temp=temp;
			
			for(int j=0;j<7;j++)
			{
				t_temp[i+j]=s[j];
			}
			
			if(occurence(t_temp)==1)
			{
				return t_temp;
			}
		}
	}
	
	return "xxx";
}
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
		
		int cc=occurence(s);
		
		if(cc>1)
		{
			cout<<"No"<<endl;
		}
		else if(cc==1)
		{
			for(int i=0;i<n;i++)
			{
				if(s[i]=='?')
				{
					s[i]='d';
				}
			}
			cout<<"Yes"<<endl;
			cout<<s<<endl;
		}
		else
		{
			string tt=check(s);
			
			if(tt=="xxx")
			{
				cout<<"No"<<endl;
			}
			else
			{
				for(int i=0;i<n;i++)
				{
					if(tt[i]=='?')
					{
						tt[i]='d';
					}
				}
				cout<<"Yes"<<endl;
				cout<<tt<<endl;
			}
		}
	}
	return 0;
}
