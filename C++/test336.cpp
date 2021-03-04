#include<bits/stdc++.h>
using namespace std;

const int maxN=50000;

long double l[maxN],p[maxN];

int main()
{
	int n;
	cin>>n;
	
	vector<pair<long double,int> > v(n);
	
	long double sum1=0,sum=0;
	
	for(int i=0;i<n;i++)
	{
		v[i].second=i;
		
		cin>>l[i]>>p[i];
		p[i]/=100;
		
		sum1+=l[i];
		
		if(p[i]==1.0)
			v[i].first=1e18;
		else
		{
			v[i].first=l[i]*p[i]/(1-p[i]);
		}
	}
	
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	long double ans=0;
	
	for(int i=0;i<n;i++)
	{		
		ans+=sum*((long double)1-p[v[i].second]);		
		sum+=l[v[i].second]*p[v[i].second];
	}
	
	cout<<fixed<<setprecision(10)<<ans+sum1<<endl;
	return 0;
}
