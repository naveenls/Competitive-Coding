#include<bits/stdc++.h>
using namespace std;
int n,k;
set<char> vow={'a','e','i','o','u'};
string last(string s)
{
	int ind=-1;
	int temp=k;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(vow.find(s[i])!=vow.end())
		{
			temp--;
			if(!temp)
			{
				ind=i;
				break;
			}
		}
	}
	if(ind==-1)
	{
		return "AA";
	}
	string ans=s.substr(ind,s.size()-ind);
	return ans;
}
string solve(string s1,string s2,string s3,string s4)
{
	string t1=last(s1);
	string t2=last(s2);
	string t3=last(s3);
	string t4=last(s4);
	
	if(s1=="AA" || s2=="AA" || s3=="AA" || s4=="AA")
		return "bbbb";
	if(t1==t2 && t2==t3 && t3==t4)
	{
		return "aaaa";
	}
	else if(t1==t3 && t2==t4)
		return "abab";
	else if(t1==t2 && t3==t4)
	{
		return "aabb";
	}
	else if(t1==t4 && t2==t3)
		return "abba";
	else
		return "bbbb";
}
int main()
{
	cin>>n>>k;
	
	vector<string> rhyme;
	for(int i=0;i<4*n;i++)
	{
		string s1,s2,s3,s4;
		cin>>s1>>s2>>s3>>s4;
		rhyme.push_back(solve(s1,s2,s3,s4));
	}
	string ans="aaaa";
	for(auto ele:rhyme)
	{
		if(ele=="bbbb")
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(ele!=ans && ans=="aaaa")
		{
			ans=ele;
		}
		if(ele!=ans && ans!="aaaa")
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
