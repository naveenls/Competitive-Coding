#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	int b[m];
	for(int j=0;j<m;j++)
	{
		cin>>b[j];
	}
	sort(a,a+n);
	sort(b,b+m);
	vector< pair<int,int> > v1;
	vector< pair<int,int> > v2;
	v1.push_back(make_pair(a[0],1));
	int sz=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			v1[sz].second++;	
		}
		else
		{
			v1.push_back(make_pair(a[i],1));
			sz++;
		}
	}
	
	v2.push_back(make_pair(b[0],1));
	sz=0;
	for(int i=1;i<m;i++)
	{
		if(b[i]==b[i-1])
		{
			v2[sz].second++;	
		}
		else
		{
			v2.push_back(make_pair(b[i],1));
			sz++;
		}
	}
	
	vector<long long> prea;
	vector<long long> preb;
	prea.push_back(0);
	preb.push_back(0);
	
	int i=0,j=0;
	while(i<v1.size() && j<v2.size())
	{
		if(v1[i].first<v2[j].first)
		{
			prea.push_back(v1[i].second);
			preb.push_back(0);
			i++;
		}
		else if(v1[i].first>v2[j].first)
		{
			preb.push_back(v2[j].second);
			prea.push_back(0);
			j++;
		}
		else
		{
			prea.push_back(v1[i].second);
			preb.push_back(v2[j].second);
			i++,j++;
		}
	}
	while(i<v1.size())
	{
		prea.push_back(v1[i].second);
		preb.push_back(0);
		i++;
	}
	while(j<v2.size())
	{
		preb.push_back(v2[j].second);
		prea.push_back(0);
		j++;
	}
	for(int i=1;i<prea.size();i++)
	{
		prea[i]+=prea[i-1];
		preb[i]+=preb[i-1];
	}
	int ind=0;
	long long max_val=-LONG_MAX;
	for(i=0;i<prea.size();i++)
	{
		//cout<<prea[i]<<' '<<preb[i]<<endl;
		if(3*(n-prea[i])+2*prea[i]-3*(m-preb[i])-2*preb[i]>max_val)
		{
			max_val=3*(n-prea[i])+2*prea[i]-3*(m-preb[i])-2*preb[i];
			ind=i;
		}
	}
	cout<<3*(n-prea[ind])+2*prea[ind]<<':'<<3*(m-preb[ind])+2*preb[ind]<<endl;
	return 0;
	
}
