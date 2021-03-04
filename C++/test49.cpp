#include<bits/stdc++.h>
using namespace std;
const int maxN=1e7+1;

int main()
{
	int n;
	cin>>n;
	int a;
	int cnt[maxN]={0};
	bool mark[maxN]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cnt[a]++;
	}
	int pre[maxN]={0};
	for(int i=2;i<maxN;i++)
	{
		if(!mark[i])
		{			
			int j=i;
			while(j<maxN)
			{
				pre[i]+=cnt[j];
				mark[j]=1;
				j+=i;
			}
		}
	}
	
	for(int i=2;i<maxN;i++)
	{
		pre[i]+=pre[i-1];
	}
	int m;
	cin>>m;
	int l,r;
	while(m--)
	{
		cin>>l>>r;
		if(l>(int)1e7)
		{
			cout<<0<<endl;
		}
		else
		{
			r=min((int)1e7,r);
			cout<<pre[r]-pre[l-1]<<endl;
		}
	}
	return 0;
}
