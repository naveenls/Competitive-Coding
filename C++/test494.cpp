#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) c.begin(),c.end()

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int> a(n);
		vector<int> b(n);
		
		int mi=1e9;
		int mi1=1e9;
		
		rep(i,n)
			cin>>a[i],mi=min(mi,a[i]);
		
		rep(i,n)
			cin>>b[i],mi1=min(mi1,b[i]);
			
		long long count=0;
		
		rep(i,n)
		{
			int val1=a[i]-mi;
			int val2=b[i]-mi1;
			
			count+=min(val1,val2);
			
			int tt=min(val1,val2);
			val1-=tt;
			val2-=tt;
			
			count+=(val1+val2);
		}
		
		cout<<count<<endl;
			
	}
}
