#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	
	long long arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	sort(arr,arr+n);
	
	int q;
	cin>>q;
	
	vector<long long> v(n-1);
	for(int i=0;i<n-1;i++)
	{
		v[i]=arr[i+1]-arr[i];
	}
	sort(v.begin(),v.end());
	
	vector<long long> sum(n-1);
	sum[0]=v[0];
	for(int i=1;i<n-1;i++)
	{
		sum[i]=v[i]+sum[i-1];
	}
	while(q--)
	{
		long long l,r;
		cin>>l>>r;
		
		long long len=r-l+1;
		if(n==1)
		{
			cout<<len<<' ';
			continue;
		}
		
		if(len>v[n-2])
		{
			//cout<<"hi"<<endl;
			cout<<len+sum[n-2]<<endl;
		}
		else
		{
			int ind=upper_bound(v.begin(),v.end(),len)-v.begin();
			if(ind==0)
			{
				cout<<n*len<<' ';
			}
			else
			{
				ind--;
				//cout<<ind<<' ';
				cout<<(n-ind-1)*len+sum[ind]<<' ';
			}
		}
	}
	return 0;
}
