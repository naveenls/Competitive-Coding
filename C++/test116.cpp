#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	
	cin>>s1>>s2;
	if(s1.size()>s2.size())
	{
		swap(s1,s2);
	}
	int cnt=0;
	
	bool flag=0;
	for(int i=1;i<s1.size();i++)
	{
		if(s1[i]!=s1[i-1])
		{
			flag=1;
			break;
		}
	}
	
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]!=s1[0])
		{
			flag=1;
			break;
		}
	}
	if(!flag)
		cnt++;
		
	int n=s1.size();
	int n1=s2.size();
	
	for(int i=2;i<=n;i++)
	{
		if(n%i==0 && n1%i==0)
		{
			flag=0;
			string temp=s1.substr(0,i);
			
			string t1="";
			for(int j=0;j<n/i;j++)
				t1+=temp;
				
			string t2="";
			for(int j=0;j<n1/i;j++)
				t2+=temp;
				
			if(t1==s1 && t2==s2)
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
