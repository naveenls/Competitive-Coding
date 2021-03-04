#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5;

int n,len,k;
long long arr[maxN];

multiset<long long> top_val,next_top;
long long top_sum=0;

void add(long long x)
{
	top_sum+=x;
	top_val.insert(x);
	if(top_val.size()>k)
	{
		auto itr=top_val.begin();
		top_val.erase(itr);
		next_top.insert(*itr);
		top_sum-=*itr;
	}
}

void del(long long x)
{
	if(next_top.find(x)!=next_top.end())
	{
		next_top.erase(next_top.find(x));
	}
	else
	{
		top_val.erase(top_val.find(x));
		top_sum-=x;
		
		if(next_top.size())
		{
			auto itr=next_top.rbegin();
			top_val.insert(*itr);
			top_sum+=*itr;
			next_top.erase(next_top.find(*itr));
		}
	}
}
long long find_max()
{
	long long ma=0;
	long long t_sum=0;
	
	for(int i=0;i<len;i++)
	{
		t_sum+=arr[i];
		if(arr[i]<0)
		{
			add(-arr[i]);
		}
	}
	//cout<<t_sum<<' '<<top_sum<<endl;
	ma=max(t_sum+2*top_sum,ma);
	
	for(int i=1;i<n-len+1;i++)
	{
		t_sum+=arr[i+len-1];
		t_sum-=arr[i-1];
		
		if(arr[i-1]<0)
		{
			del(-arr[i-1]);
		}
		if(arr[i+len-1]<0)
		{
			add(-arr[i+len-1]);
		}
		//cout<<t_sum<<' '<<top_sum<<endl;
		ma=max(ma,t_sum+2*top_sum);
	}
	return ma;
}
int main()
{
	
	cin>>n>>len;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	cin>>k;
	
	long long ans=find_max();
	
	for(int i=0;i<n;i++)
		arr[i]*=-1;
		
	top_val.clear(),next_top.clear();
	top_sum=0;
	
	cout<<max(ans,find_max());
	return 0;
}
