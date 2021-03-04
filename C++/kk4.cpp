#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > ans;

void factorize(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int a=i;
			int b=n/i;
			
			if(a!=b && __gcd(a+b,n)==1)
			{
				ans.push_back({a,b});
				return;
			}	
		}	
	}
	ans.push_back({-1,-1});
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		factorize(arr[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<ans[i].first<<' ';
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ans[i].second<<' ';
	}
	return 0;
}
