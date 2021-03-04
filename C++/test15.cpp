#include<bits/stdc++.h>
using namespace std;

char n1,n2;
bool check(char a,char b,char c,char d)
{
	string s1="";
	string s2="";
	s1.push_back(a);
	s1.push_back(b);
	
	s2.push_back(c);
	s2.push_back(d);
	
	map<string,vector<string> > u;

	u["00"]={"00"};
	u["01"]={"11","01"};
	u["10"]={"11","10"};
	u["11"]={"10","01","11"};
	
	for(auto ele:u[s1])
	{
		if(ele==s2)
		{
			n1=ele[0];
			n2=ele[1];
			return true;
		}
	}
	for(auto ele:u[s1])
	{
		if(ele[0]==s2[0])
		{
			n1=ele[0];
			n2=ele[1];
			return true;
		}
	}
	return false;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size()!=s2.size())
	{
		cout<<"NO";
		return 0;
	}
	
	for(int i=0;i<n-1;i++)
	{
		if(check(s1[i],s1[i+1],s2[i],s2[i+1]))
		{
			s1[i]=n1;
			s1[i+1]=n2;
		}
		else
		{
			cout<<"NO";
			return 0;
		}
	}
	if(s1[s.size()-1]==s2[s.size()-1])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
	
}
