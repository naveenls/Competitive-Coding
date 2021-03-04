#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long d;
	cin>>n>>d;
	
	long long a,b;
	cin>>a>>b;
	
	vector<pair<long long ,int> > v(n);
	
	long long x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		v[i]={a*x+b*y,i+1};
	}
	
	sort(v.begin(),v.end());
	
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		if(d>=v[i].first)
		{
			d-=v[i].first;
			ans.push_back(v[i].second);
		}
		else
		{
			break;
		}
	}
	cout<<ans.size()<<endl;
	for(auto ele:ans)
		cout<<ele<<' ';
	return 0;
}
