#include<bits/stdc++.h>
using namespace std;

set<pair<int,int> > s;

bool check(int k,int n)
{
	for(auto ele:s)
	{
		int t1=(ele.first+k)%n;
		int t2=(ele.second+k)%n;
		
		if(t1>t2)
			swap(t1,t2);
			
		if(s.find({t1,t2})==s.end())
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n,m;
	
	cin>>n>>m;
	
	int a,b;
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--,b--;
		if(a>b)
			swap(a,b);
		
		s.insert({a,b});
	}
	
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(check(i,n))
			{
				cout<<"Yes"<<endl;
				return 0;
			}
			if(i!=1 && check(n/i,n))
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
