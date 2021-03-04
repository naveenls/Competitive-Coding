#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long double,long double> &a,pair<long double,long double> &b)
{		
	return a.second/a.first > b.second/b.first;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
	
	int n;
	cin>>n;
	
	vector<pair<long double,long double> > v;
	
	long double a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a)
		{
			v.push_back({a,b});
		}
	}
	
	sort(v.begin(),v.end(),compare);
		
	int cnt=0;
	
	for(int i=0;i<v.size();)
	{
		int add_slope=abs(v[i].first);
		
		int j=i+1;
		while(j<v.size() && v[i].second*v[j].first==v[i].first*v[j].second)
		{
			add_slope+=abs(v[j].first);
			j++;
		}
		
		if(add_slope!=0)
		{
			cnt++;
		}
		i=j;
	}
	cout<<cnt<<endl;
	return 0;
}
