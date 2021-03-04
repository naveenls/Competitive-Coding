#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;
	
	long double x[n],y[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	bool flag=0;
	
	set<pair<pair<int,int>,int> > s;
		
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int a=y[i]-y[j];
			int b=x[i]-x[j];
			int c=y[i]*x[j]-y[j]*x[i];
			
			int gcd=__gcd(abs(a),abs(b));
			gcd=__gcd(gcd,abs(c));
			
			a/=gcd;
			b/=gcd;
			c/=gcd;
			
			s.insert({{a,b},c});
		}
	}
	
	map<pair<int,int> ,int > mp;
	
	for(auto ele:s)
	{
		mp[ele.first]++;
	}
	
	long long t_pairs=s.size();
	
	long long ans=t_pairs*(t_pairs-1)/2;
	
	for(auto ele:mp)
	{
		//cout<<ele.first<<' '<<ele.second<<endl;
		ans-=ele.second*(ele.second-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}
