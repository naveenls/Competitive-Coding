#include<bits/stdc++.h>
using namespace std;

unsigned long long find_min_max(long long a)
{
	vector<unsigned long long> dig;
	unsigned long long temp=a;
	while(a)
	{
		dig.push_back(a%10);
		a/=10;
	}
	unsigned long long mi=11;
	unsigned long long ma=0;
	for(int i=0;i<dig.size();i++)
	{
		mi=min(dig[i],mi);
		ma=max(ma,dig[i]);
	}
	return temp+mi*ma;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long a,k;
		cin>>a>>k;
		while(k>1)
		{
			unsigned long long temp=find_min_max(a);
			if(temp==a)
			{
				break;
			}
			else
			{
				a=temp;
			}
			k--;
		}
		cout<<a<<endl;
	}
	return 0;
}
