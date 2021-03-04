#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<pair<int,int> > v(n);
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		v[i]={a,b};
	}
	sort(v.begin(),v.end());
	bool mark[n]={0};
	int i=0;
	while(i<n)
	{
		bool flag=0;
		for(int j=i+1;j<n;j++)
		{
			if(v[j].second<v[i].second)
			{
				mark[j]=1;
			}
			else
			{
				i=j;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			break;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
		cnt+=mark[i];
	
	cout<<cnt<<endl;
}
