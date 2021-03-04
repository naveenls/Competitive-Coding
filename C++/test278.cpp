#include<bits/stdc++.h>
using namespace std;

long long find_sum(int n)
{
	if(n<3)
		return 0;
		
	long long temp=n;
	
	return (temp*(temp-1)*(temp-2))/6;
}
int main()
{
	int n;
	cin>>n;
	
	int x[n],y[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	map<pair<int,pair<int,int> > , set<int> > mp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int a=x[j]-x[i];
			int b=y[j]-y[i];
			int c=y[i]*x[j]-y[j]*x[i];
			
			int gcd=__gcd(abs(a),abs(b));
			gcd=__gcd(gcd,abs(c));
			
			a/=gcd;
			b/=gcd;
			c/=gcd;
			
			if(a<0)
			{
				a*=-1;
				b*=-1;
				c*=-1;
			}
			else if(a==0 && b<0)
			{
				b*=-1;
				c*=-1;
			}
			mp[{c,{a,b}}].insert(i);
			mp[{c,{a,b}}].insert(j);
		}
	}
	
	long long ans=find_sum(n);
	
	for(auto ele:mp)
	{
		int sz=ele.second.size();
		ans-=find_sum(sz);
	}
	cout<<ans<<endl;
	return 0;
}
