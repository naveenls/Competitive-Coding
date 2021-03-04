#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long> &arr,int s,int e,int st)
{
	long long initial=0;
	
	set<long long> prev;
	
	for(int i=s;i!=e;i+=st)
	{
		initial|=arr[i];
		
		if(prev.count(initial))
		{
			return true;
		}
		
		prev.insert(initial);
	}
	
	return false;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
			
		vector<long long> arr(n);
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		if(check(arr,0,n,1) || check(arr,n-1,-1,-1))
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
