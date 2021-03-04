#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n;i+=2)
	{
		v.push_back(arr[i]);
	}
	
	for(int i=1;i<n;i+=2)
	{
		v.push_back(arr[i]);
	}
	
	vector<int> v_new=v;
	
	for(auto ele:v)
	{
		v_new.push_back(ele);
	}
	
	long long sum=0;
	
	long long ma=0;
	
	int len=(n+1)/2;
	
	for(int i=0;i<len;i++)
	{
		sum+=v_new[i];
	}
	
	ma=max(ma,sum);
	
	for(int i=0;i<v_new.size()-len;i++)
	{
		int j=i+len;
		sum+=v_new[j]-v_new[i];
		
		ma=max(ma,sum);
	}
	cout<<ma<<endl;
	return 0;
}
