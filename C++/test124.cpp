#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6+1;

int main()
{
	int n;
	cin>>n;
	
	int arr[maxN]={0};
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr[a]=1;
	}
	vector<int> v;	
	for(int i=1;i<maxN;i++)
	{
		if(arr[i])
			v.push_back(i);
	}
	int ma=0;
	
	for(int i=2;i<maxN;i++)
	{
		if(arr[i])
		{
			int j=2*i;
			while(j<maxN)
			{
				auto itr=lower_bound(v.begin(),v.end(),j-1);
				--itr;
				ma=max(ma,*itr%j);
				j+=i;
			}
		}
	}
	cout<<ma<<endl;
	return 0;
}
