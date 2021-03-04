#include<bits/stdc++.h>
using namespace std;

set<int> B;

int fact(int a)
{
	int ans=0;
	//cout<<a<<' ';
	int cnt;
	if(a%2==0)
	{
		cnt=0;
		while(a%2==0)
		{
			a/=2;
			cnt++;
		}
		if(B.find(2)!=B.end())
			ans-=cnt;
		else
			ans+=cnt;
	}
	
	for(int i=3;i*i<=a;i++)
	{
		if(a%i==0)
		{
			cnt=0;
			while(a%i==0)
			{
				a/=i;
				cnt++;
			}
			if(B.find(i)!=B.end())
				ans-=cnt;
			else
				ans+=cnt;
		}
	}
	if(a>1)
	{
		if(B.find(a)!=B.end())
			ans-=1;
		else
			ans+=1;
	}
	return ans;
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	int a[n];
	int b[n];
	
	int prefix_gcd[n];
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
		B.insert(b[i]);
	}
	
	prefix_gcd[0]=a[0];
	ans+=fact(a[0]);
	for(int i=1;i<n;i++)
	{
		ans+=fact(a[i]);
		prefix_gcd[i]=__gcd(a[i],prefix_gcd[i-1]);
	}
	
	for(int i=0;i<n;i++)
	{
		prefix_gcd[i]=fact(prefix_gcd[i]);
		//cout<<prefix_gcd[i]<<' ';
	}
	//cout<<endl;
	int prev_dec=0;
	for(int i=n-1;i>=0;i--)
	{
		if(prefix_gcd[i]-prev_dec<0)
		{
			ans-=(prefix_gcd[i]-prev_dec)*(i+1);
			prev_dec=prefix_gcd[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
