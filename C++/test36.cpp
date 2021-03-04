#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	string s;
	cin>>k;
	cin>>s;
	
	int arr[s.size()+1];
	arr[0]=0;
	for(int i=1;i<=s.size();i++)
	{
		arr[i]=arr[i-1]+(s[i-1]=='1');
	}
	int maxN=1e6+10;
	long long val[maxN]={0};
	for(int i=0;i<=s.size();i++)
	{
		val[arr[i]]++;
	}
	long long ans=0;
	if(k==0)
	{
		ans+=val[0];
		for(int i=1;i<=s.size();i++)
		{
			if(s[i-1]=='0')
				if(arr[i]+k<maxN)
					ans+=val[arr[i]+k];
		}
	}
	else
	{
		for(int i=0;i<=s.size();i++)
		{
			if(arr[i]+k<maxN)
				ans+=val[arr[i]+k];
		}
	}
	cout<<ans<<endl;
	return 0;
	
}
