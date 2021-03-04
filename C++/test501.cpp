#include<bits/stdc++.h>
using namespace std;

const int maxN=2000;
long double x[2][maxN],h[maxN];

long double check(long double slope,int n)
{
	vector<pair<long double,long double> > v;
	
	for(int i=0;i<n;i++)
	{
		long double c1=h[i]-slope*x[0][i];
		long double c2=h[i]-slope*x[1][i];
		
		long double x1=-c1/slope;
		long double x2=-c2/slope;
		
		v.push_back({x1,x2});
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0;i<n-1;i++)
	{
		if(v[i].second>v[i+1].first)
		{
			return -1.0;
		}
	}
	
	return v[n-1].second-v[0].first;
}

long double check1(int n)
{
	vector<pair<long double,long double> > v;
	
	for(int i=0;i<n;i++)
	{
		v.push_back({x[0][i],x[1][i]});
	}
	
	sort(v.begin(),v.end());
	for(int i=0;i<n-1;i++)
	{
		if(v[i].second>v[i+1].first)
		{
			return -1.0;
		}
	}
	
	return v[n-1].second-v[0].first;
	
}
int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>x[0][i]>>x[1][i]>>h[i];
	}

	long double ans=1e18;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=0;k<2;k++)
			{
				for(int l=0;l<2;l++)
				{
					long double x1=x[k][i];
					long double x2=x[l][j];
					
					if(x2!=x1)
					{
						long double slope=(h[j]-h[i])/(x2-x1);
					
						long double val1=check(slope,n);
						if(val1!=-1)
							ans=min(ans,val1);
					}
				}
			}
		}
	}
	
	long double val1=check1(n);
	
	if(val1!=-1)
		ans=min(ans,val1);
		
	cout<<fixed<<setprecision(10)<<ans<<endl;
}
