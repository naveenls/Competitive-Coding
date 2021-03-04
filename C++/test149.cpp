#include<bits/stdc++.h>
using namespace std;

long long m;

int main()
{
	int n;
	cin>>n;
	
	vector<pair<int,int> > a(2*n);
	
	int cc;
	
	for(int i=0;i<n;i++)
	{
		cin>>cc;
		a[i]={cc,i};
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>cc;
		a[i+n]={cc,i};
	}
	sort(a.begin(),a.end());
	
	cin>>m;
		
	vector<int> tt;
	
	int sz=0;
	
	tt.push_back(1);
	
	long long ans=1;
	long long cnt=0;
	
	vector<int> factor;
	for(int i=1;i<2*n;i++)
	{
		if(a[i].first==a[i-1].first)
		{
			if(a[i].second==a[i-1].second)
			{
				tt[sz]++;
			}
			else
			{
				tt.push_back(1);
				sz++;
			}
		}
		else
		{
			long long a=0;
		
			for(auto ele:tt)
			{
				a+=ele;
				if(ele==2)
					cnt++;
			}
			
			factor.push_back(a);
			
			tt.clear();
			sz=0;
			tt.push_back(1);
		}
	}
	
	long long te=0;
		
	for(auto ele:tt)
	{
		te+=ele;
		if(ele==2)
			cnt++;
	}
	
	factor.push_back(te);
			
	for(auto ele:factor)
	{
		for(int i=1;i<=ele;i++)
		{
			int ttemp=i;
			while(ttemp%2==0 && cnt)
			{
				cnt--;
				ttemp/=2;
			}
			ans=(ans*ttemp)%m;
		}
	}
	cout<<ans<<endl;
}
