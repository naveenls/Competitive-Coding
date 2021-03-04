#include<bits/stdc++.h>
using namespace std;

vector<int> factors;

void factorize(int a)
{
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			factors.push_back(i);
			
			while(a%i==0)
			{
				a/=i;
			}
		}
	}
	
	if(a>1)
		factors.push_back(a);
}

vector<int> ones;

long long find_ans(int l,int r,int val)
{
	long long ans=0;
	for(int i=l;i<=r;i++)
	{
		ans+=(long long)abs(ones[i]-val);
	}
	return ans;
	
}
long long find_min(int len)
{
	long long ans=0;
	for(int i=0;i<=ones.size()-len;i+=len)
	{
		int j=i+len-1;
		
		if(len%2)
		{
			ans+=find_ans(i,j,ones[i+len/2]);
		}
		else
		{
			ans+=min(find_ans(i,j,ones[i+len/2]),find_ans(i,j,ones[i+len/2-1]));
		}
	}	
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(temp)
		{
			ones.push_back(i);
		}
	}
	
	long long mi=1e18;
	
	factorize(ones.size());
	
	if(factors.size())
	{
		mi=min(mi,find_min(factors[0]));
	}
	
	if(mi==1e18)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<mi<<endl;
	}
	return 0;
}
