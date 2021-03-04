#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector< pair<int,int> > v(n);
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v[i]={a,i+1};
	}
	sort(v.begin(),v.end());
	
	cout<<n-(n/2)<<endl;
	for(int i=0;i<n;i+=2)
	{
		cout<<v[i].second<<' ';
	}
	cout<<endl;
	cout<<n/2<<endl;
	for(int i=1;i<n;i+=2)
	{
		cout<<v[i].second<<' ';
	}
	cout<<endl;
	return 0;
}
