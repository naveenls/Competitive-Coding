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
		v[i]=make_pair(a,b);
	}
	sort(v.begin(),v.end());
	int mx=v[0].second;
	for(int i=1;i<n;i++)
	{
		if(v[i].second<mx)
		{
			mx=v[i].first;
		}
		else
		{
			mx=v[i].second;
		}
	}
	cout<<mx<<endl;
	return 0;
	
}
