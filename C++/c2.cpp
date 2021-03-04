#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		bool mark[n+1]={0};
		for(int i=0;i<n;i++)
		{
			mark[arr[i]]=1;
		}
		vector<int> v;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(mark[i])
			{
				cnt++;
				v.push_back(i);
			}
		}
		if(cnt>k)
		{
			cout<<-1<<endl;
		}
		else
		{
			int temp=v[cnt-1];
			while(cnt<k)
			{
				v.push_back(temp);
				cnt++;
			}
			cout<<n*k<<endl;
			for(int i=0;i<n*k;i++)
			{
				cout<<v[i%k]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
