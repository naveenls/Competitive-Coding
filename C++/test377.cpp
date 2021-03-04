#include<bits/stdc++.h>
using namespace std;

int a,b;

void solve(int n)
{
	map<int,int> mp1,mp2;
	
	int x,y;
	
	int t_num=4*n-1;
	
	for(int i=0;i<t_num;i++)
	{
		cin>>a>>b;
		
		mp1[a]++,mp2[b]++;
	}
	
	auto itr=mp1.begin();
	
	for(;itr!=mp1.end();++itr)
	{
		if(itr->second%2==1)
		{
			x=itr->first;
		}
	}
	
	itr=mp2.begin();
	
	for(;itr!=mp2.end();++itr)
	{
		if(itr->second%2==1)
		{
			y=itr->first;
		}
	}
	
	cout<<x<<' '<<y<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		
		solve(n);
	}
	return 0;
}
