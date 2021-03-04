#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		
		int t=min(n/k,m);
		
		int pp=k-1;
		
		int rem=m-t;
		int maxi=(rem+pp-1)/pp;
		
		cout<<t-maxi<<endl;
	}
	return 0;
}
