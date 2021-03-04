#include<bits/stdc++.h>
using namespace std;

long long n;

long long calc(long long val)
{
	long long temp=val;
	vector<int> v,v1;
	
	while(temp)
	{
		v.push_back(temp%2);
		temp/=2;
	}
	
	temp=n;
	
	while(temp)
	{
		v1.push_back(temp%2);
		temp/=2;
	}
	
	reverse(v.begin(),v.end());
	reverse(v1.begin(),v1.end());
	
	long long ans=(1LL<<(v1.size()-v.size()))-1;
	//cout<<val<<' '<<ans<<endl;
	
	bool flag=0;
	
	for(int i=0;i<v.size();i++)
	{
		if(v1[i]<v[i])
		{
			return ans;
		}
		else if(v1[i]>v[i])
		{
			flag=1;
			break;
		}
	}
	temp=0;
	
	if(flag)
	{
		temp=(1LL<<(v1.size()-v.size()));
		return temp+ans;
	}
	
	long long mul=1;
	
	for(int i=v1.size()-1;i>=v.size();i--)
	{
		if(v1[i])
		{
			temp+=mul;	
		}
		mul*=2;
	}

	return ans+temp+1;
}

long long check(long long val)
{	
	long long ans=0;
	ans+=calc(val);
	
	if(val%2)
	{
		return ans;	
	}
	
	val++;
		
	return ans+calc(val);
}

int main()
{
	long long k;
	cin>>n>>k;
	
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	if(n==2)
	{
		if(k==1)
		{
			cout<<2<<endl;
		}
		else
		{
			cout<<1<<endl;
		}
		return 0;
	}
	
	long long l1=1;
	long long r1=(n+1)/2;
	
	long long ans1=0,ans2=0;
	
	while(l1<=r1)
	{
		long long mid=(l1+r1)/2;
		if(check(2*mid-1)>=k)
		{
			ans1=mid;
			l1=mid+1;
		}
		else
		{
			r1=mid-1;
		}
	}
	
	l1=1,r1=n/2;
	
	while(l1<=r1)
	{
		int mid=(l1+r1)/2;
		if(check(2*mid)>=k)
		{
			ans2=mid;
			l1=mid+1;
		}
		else
		{
			r1=mid-1;
		}
	}
	
	cout<<max(2*ans1-1,2*ans2)<<endl;
}
