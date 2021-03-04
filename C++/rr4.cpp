#include<bits/stdc++.h>
using namespace std;

int n,k;
const int maxN=2*1e5;

int arr[maxN];

bool check(int val)
{
	int len=0;
	
	for(int i=0;i<n;i++)
	{
		if(len%2==0)
		{
			if(arr[i]<=val)
				len++;
		}
		else
		{
			len++;
		}
	}
	
	int len1=0;
	
	for(int i=0;i<n;i++)
	{
		if(len1%2)
		{
			if(arr[i]<=val)
				len1++;
		}
		else
		{
			len1++;
		}
	}
	
	return len>=k || len1>=k;
}
int main()
{
	cin>>n>>k;
		
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		v[i]=arr[i];
	}	
	sort(v.begin(),v.end());
	
	int l=0,r=n-1;
	
	int ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		
		if(check(v[mid]))
		{
			ans=v[mid];
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
