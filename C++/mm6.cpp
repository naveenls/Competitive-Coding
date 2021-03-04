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
		
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		for(int i=0;i<n;i++)
			cin>>b[i];
		
		if(n%2)
		{
			if(a[n/2]!=b[n/2])
			{
				cout<<"No"<<endl;
				continue;
			}
		}
		
		multiset<pair<int,int> > mp;
		
		for(int i=0;i<n/2;i++)
		{
			mp.insert({b[i],b[n-i-1]});
		}
		bool flag=0;
		for(int i=0;i<n/2;i++)
		{
			if(mp.find({a[i],a[n-i-1]})!=mp.end())
			{
				mp.erase(mp.find({a[i],a[n-i-1]}));
			}
			else if(mp.find({a[n-i-1],a[i]})!=mp.end())
			{
				mp.erase(mp.find({a[n-i-1],a[i]}));
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;	
}
