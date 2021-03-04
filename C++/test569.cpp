#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	vector<int> diff;
	
	for(int i=0;i<n-1;i++)
	{
		diff.push_back(arr[i+1]-arr[i]);
	}
	
	int len=1;
	int ma=0;
	
	for(int i=1;i<diff.size();i++)
	{
		if(diff[i]==diff[i-1])
		{
			len++;
		}
		else
		{
			ma=max(ma,len);
			len=1;
		}
	}
	
	ma=max(ma,len);
	
	cout<<ma+1<<endl;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
