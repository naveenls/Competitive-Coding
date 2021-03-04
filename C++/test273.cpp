#include<bits/stdc++.h>
using namespace std;

int n,k;
const int maxN=1e5;
int arr[maxN+1]={0};

bool check(int len)
{
	if(len==0)
		return true;
		
	int sum=0;
	for(int i=0;i<len;i++)
	{
		sum+=arr[i];
	}
	if(sum<=k || len-sum<=k)
		return true;
		
	for(int i=0;i<n-len;i++)
	{
		int j=i+len;
		sum+=arr[j];
		sum-=arr[i];
		
		if(sum<=k || len-sum<=k)
			return true;
	}
	
	return false;
}
int main()
{
	cin>>n>>k;
	
	string s;
	cin>>s;
	
	for(int i=0;i<n;i++)
	{
		arr[i]=(s[i]=='b');
	}
	
	int l=k,r=n;
	int ans;
	
	while(l<=r)
	{
		int mid=(l+r)/2;
		
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
