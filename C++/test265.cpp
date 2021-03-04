#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	long long x[n],y[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	
//	int ref1=0;
		
	map<pair<int,int>,int > cnt;
	for(int i=1;i<n;i++)
	{
		int n_x=x[i]-x[0];
		int n_y=y[i]-y[0];
		
		if(n_y<0)
			n_x*=-1;
		
		int gcd=__gcd(abs(n_x),abs(n_y));
		n_x/=gcd;
		n_y/=gcd;
		
		cnt[{n_x,n_y}]++;
	}
	
	int mx=0;
	pair<int,int> max_val;
	
	for(auto ele:cnt)
	{
		if(ele.second>mx)
		{
			mx=ele.second;
			max_val=ele.first;	
		}
	}
	
	int flag[n]={0};
	int ref2=-1;
	for(int i=1;i<n;i++)
	{
		int n_x=x[i]-x[0];
		int n_y=y[i]-y[0];
		
		if(n_y<0)
			n_x*=-1;
		
		int gcd=__gcd(abs(n_x),abs(n_y));
		n_x/=gcd;
		n_y/=gcd;
		
		if(make_pair(n_x,n_y)!=max_val)
		{
			//cout<<i<<endl;
			flag[i]=1;
			ref2=i;
		}
	}
	if(ref2==-1)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	
	set<pair<int,int> > s;
	for(int i=1;i<n;i++)
	{
		if(flag[i])
		{
			int n_x=x[i]-x[ref2];
			int n_y=y[i]-y[ref2];
			
			if(n_y<0)
				n_x*=-1;
			
			int gcd=__gcd(abs(n_x),abs(n_y));
			n_x/=gcd;
			n_y/=gcd;
		
			if(n_x || n_y)
				s.insert({n_x,n_y});
		}
	}
	if(s.size()<=1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
