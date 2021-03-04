#include<bits/stdc++.h>
using namespace std;

int n;

long long find_val(long long arr[],long long x)
{
	long long val=0;
	for(int i=0;i<n;i++)
	{
		val+=min(x,arr[i]);
	}
	return val;
}
int main()
{
	cin>>n;
	
	long long k;
	cin>>k;
	
	long long arr[n];
	
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
		
	if(k>sum)
	{
		cout<<-1<<endl;
		return 0;
	}
	long long l=0,r=1e9;
	
	long long ans;
	
	while(l<=r)
	{
		long long mid=(l+r)/2;
		
		if(find_val(arr,mid)<=k)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	
	long long val=k-find_val(arr,ans);
	
	vector<int> v;
	set<int> s;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>ans)
		{
			if(val)
			{
				val--;
			}
			else
			{
				v.push_back(i+1);
				s.insert(i+1);
			}
			arr[i]--;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]>ans)
		{
			if(s.find(i+1)!=s.end())
				break;
			else
				v.push_back(i+1);
		}
	}
	
	for(auto ele:v)
	{
		cout<<ele<<' ';
	}
	return 0;
}
