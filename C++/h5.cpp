#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int N=(n+1)/2;
	
	long long arr[N+1];
	for(int i=1;i<=N;i++)
	{
		cin>>arr[i];
	}
	long long x;
	cin>>x;
	
	long long a[N+1];
	a[0]=0;
	for(int i=1;i<=N;i++)
	{
		a[i]=x-arr[i];
		a[i]+=a[i-1];
	}
	long long mi[N+1];
	long long s1=0;
	mi[0]=1e18;
	for(int i=1;i<=N;i++)
	{
		s1+=arr[i];
		mi[i]=min(a[i],mi[i-1]);
	}
	mi[0]=0;
	for(int i=N;i<=n;i++)
	{
		if(s1+mi[n-i]>0 && s1>0)
		{
			cout<<i<<endl;
			return 0;
		}
		s1+=x;
	}
	
	cout<<-1<<endl;
	return 0;
}
