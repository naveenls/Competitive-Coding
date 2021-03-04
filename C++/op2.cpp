#include<bits/stdc++.h>
using namespace std;

long long find_prod(long long arr[])
{
	long long ans=1;
	for(int i=0;i<10;i++)
	{
		ans*=arr[i];
	}
	return ans;
	
}

int main()
{
	long long k;
	cin>>k;
	
	long long arr[10];
	for(int i=0;i<10;i++)
		arr[i]=1;
	
	int start=0;
	
	while(find_prod(arr)<k)
	{
		arr[start]++;
		start++;
		
		start%=10;
	}
	
	string s="codeforces";
	
	for(int i=0;i<10;i++)
	{
		while(arr[i]--)
		{
			cout<<s[i];
		}
	}
	
	return 0;
}
