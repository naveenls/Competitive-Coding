#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[n],b[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	multiset<int> ss;
		
	for(int i=0;i<n;i++)
		cin>>b[i],ss.insert(b[i]);
		
	for(int i=0;i<n;i++)
	{
		int val=n-a[i];
		auto itr=ss.lower_bound(val);
		
		int val1=n;
		if(itr!=ss.end())
		{
			val1=*itr;
		}
		
		int val2=n;
		auto itr1=ss.lower_bound(a[i]);
		
		if(itr1!=ss.end())
		{
			val2=*itr1;
		}
		
		int val3=*ss.lower_bound(0);
		int min_val=(a[i]+val3)%n;
		int mi=val3;
		
		if(val1!=n)
		{
			if(min_val>(a[i]+val1)%n)
			{
				min_val=(a[i]+val1)%n;
				mi=val1;
			}
		}
		if(val2!=n)
		{
			if(min_val>(a[i]+val2)%n)
			{
				min_val=(a[i]+val2)%n;
				mi=val2;
			}
		}
		cout<<min_val<<' ';
		ss.erase(ss.find(mi));
	}
	return 0;
}
