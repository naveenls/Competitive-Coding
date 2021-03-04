#include<bits/stdc++.h>
using namespace std;

long long a,b,c;

long long get_val(long long i)
{
	return b*(pow(i,a))+c;
}
int main()
{
	
	cin>>a>>b>>c;
	vector<long long> ans;
	for(long long i=1;i<=90;i++)
	{
		long long x=get_val(i);
		
		if(x>=1e9)
			continue;
			
		long long sum=0;
		int temp=x;
		while(x)
		{
			sum+=x%10;
			x/=10;
		}
		if(sum==i)
		{
			ans.push_back(temp);
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<' ';
	
	return 0;
}
