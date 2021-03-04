#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

int DP[maxN][26];

string a="",b="",c="";

bool check(int n)
{
	cout<<a<<' '<<b<<' '<<c<<endl;
	set<int> s;
	
	int s_ind=0;
	
	for(int i=0;i<a.size();i++)
	{
		if(s_ind==n)
			return false;
	
		s_ind=DP[s_ind][a[i]-'a'];

		if(s_ind==n)
			return false;
			
		s.insert(s_ind);	
		s_ind++;
	}
	
	s_ind=0;
	
	for(int i=0;i<b.size();i++)
	{
		if(s_ind==n)
			return false;
			
		s_ind=DP[s_ind][b[i]-'a'];
		
		if(s_ind==n)
			return false;
			
		if(s.find(s_ind)!=s.end())
		{
			i--;
		}
		else
		{
			s.insert(s_ind);
		}
		s_ind++;
	}
	
	s_ind=0;
	
	for(int i=0;i<c.size();i++)
	{
		if(s_ind==n)
			return false;
			
		s_ind=DP[s_ind][c[i]-'a'];
		
		if(s_ind==n)
			return false;
			
		if(s.find(s_ind)!=s.end())
		{
			i--;
		}
		else
		{
			s.insert(s_ind);
		}
		s_ind++;
	}
	return true;
}
int main()
{
	int n,q;
	cin>>n>>q;
	
	string s;
	cin>>s;
	
	memset(DP,-1,sizeof(DP));
	
	for(int i=0;i<26;i++)
	{
		DP[n-1][i]=n;
	}
	for(int i=0;i<n;i++)
	{
		DP[i][s[i]-'a']=i;
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<26;j++)
		{
			if(DP[i][j]==-1)
				DP[i][j]=DP[i+1][j];
		}
	}
	
	while(q--)
	{
		char c1,c2,c3;
		
		cin>>c1;
		if(c1=='+')
		{
			cin>>c2>>c3;
			
			if(c2=='1')
				a.push_back(c3);
			else if(c2=='2')
				b.push_back(c3);
			else
				c.push_back(c3);
				
			if(check(n))
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		else
		{
			cin>>c2;
			
			if(c2=='1')
				a.pop_back();
			else if(c2=='2')
				b.pop_back();
			else
				c.pop_back();
				
			if(check(n))
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
