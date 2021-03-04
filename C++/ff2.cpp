#include<bits/stdc++.h>
using namespace std;

int find_min(string s)
{
	int n=s.size();
	
	int DP[n]={0};
	int cnt_1=0;
	
	DP[0]=s[0]-'0';
	
	for(int i=1;i<n;i++)
	{
		if(s[i]=='1')
		{
			cnt_1++;
			DP[i]=1+DP[i-1];
		}
		else
			DP[i]=DP[i-1];
	}
	
	int mn=1e9;
	
	for(int i=0;i<n;i++)
	{
		mn=min(mn,i+1-DP[i] + DP[n-1]-DP[i]);
	}
	mn=min(mn,cnt_1);
	return mn;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		if(s.size()<3)
		{
			cout<<0<<endl;
		}
		else
		{
			int a=find_min(s);
			reverse(s.begin(),s.end());
			a=min(a,find_min(s));
			cout<<a<<endl;
		}
	}
	return 0;
}
