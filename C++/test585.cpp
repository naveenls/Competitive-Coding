#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;
long double arr[maxN];
int n;
long double d;

bool check(long double mid)
{
	long double prev_shot=-1e10;
	
	for(int i=0;i<n;i++)
	{
		long double l=arr[i];
		long double r=d+arr[i];
		
		if(prev_shot+mid>r)
		{
			return false;
		}
		
		cout<<prev_shot<<' ';
		
		prev_shot=max(prev_shot+mid,l);
	}
	cout<<endl;
	
	return true;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(int i=0;i<n;++i)
		{
			cin>>arr[i];
		}
		
		cin>>d;
		
		sort(arr,arr+n);
		
		long double l=0,r=1e10;
		
		for(int i=0;i<=45;i++)
		{
			long double mid=(l+r)/2.0;
			
			//cout<<mid<<endl;
			
			if(check(mid))
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		
		cout<<fixed<<setprecision(10)<<l<<endl;
	}
	return 0;	
}
