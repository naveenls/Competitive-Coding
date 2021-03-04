#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long n;
		cin>>n;
		
		long long k=(n-1)/3;
		long long p=n%3;
		
		vector<int> v;
		k++;
		
		while(k)
		{
			v.push_back(k%2);
			k/=2;
		}
		
		vector<int> ans;
		for(auto ele:v)
		{
			if(ele)
			{
				if(p==1)
				{
					ans.push_back(1);
					ans.push_back(0);
				}
				else if(p==2)
				{
					ans.push_back(0);
					ans.push_back(1);
				}
				else
				{
					ans.push_back(1);
					ans.push_back(1);
				}
			}
			else
			{
				ans.push_back(0);
				ans.push_back(0);
			}
		}
		
		long long val=0;
		long long res=1;
		for(int i=0;i<ans.size();i++)
		{
			if(ans[i])
				val+=res;
			res*=2;
		}
		cout<<val<<endl;
	}
	return 0;
}
