#include<bits/stdc++.h>
using namespace std;

void factorize(long long q)
{
	if(q==1)
	{
		cout<<"1\n0";
		return;
	}
	vector< pair<long long,int> > v;
	int count=0;
	int temp=q;
	for(long long i=2;i<=sqrt(temp)+3;i++)
	{
		if(q%i==0)
		{
			int c=0;
			while(q%i==0)
			{	
				c++;
				q/=i;
			}
			count+=c;
			v.push_back({i,c});
		}
	}
	if(count<2)
	{
		cout<<"1\n0";
		return;
	}
	if(count>2)
	{
		cout<<1<<endl;
		if(v.size()==1)
		{
			cout<<v[0].first*v[0].first;
		}
		else
		{
			cout<<v[0].first*v[1].first;
		}
	}
	else
	{
		cout<<2;
		return;
	}
}
int main()
{
	long long q;
	cin>>q;
	factorize(q);
	return 0;
}
