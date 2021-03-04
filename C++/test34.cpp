#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long arr[n];
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	if(sum%3)
	{
		cout<<0<<endl;
	}
	else
	{
		sum=sum/3;
		vector<int> l,r;
		long long s=0;
		for(int i=0;i<n;i++)
		{
			s+=arr[i];
			if(s==sum)
				l.push_back(i);
		}
		s=0;
		for(int i=n-1;i>=0;i--)
		{
			s+=arr[i];
			if(s==sum)
				r.push_back(i);
		}
		sort(r.begin(),r.end());
		long long ans=0;
		for(int i=0;i<l.size();i++)
		{
			int ind=upper_bound(r.begin(),r.end(),l[i]+1)-r.begin();
			ans+=(long long)(r.size()-ind);
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}
