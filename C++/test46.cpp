#include<bits/stdc++.h>
using namespace std;

//long long mod=1e9+7;
int main()
{
	int n;
	cin>>n;
	int a;
	int cnt[101]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cnt[a]++;
	}
	int mx=cnt[0];
	for(int i=1;i<=100;i++)
	{
		cnt[i]+=cnt[i-1];
		mx=max(mx,(cnt[i]+i)/(i+1));
	}
	cout<<mx<<endl;
	return 0;
}
