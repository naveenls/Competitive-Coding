#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int x,y;
		
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
		}
		
		long long sum=n;
		n/=2;
		
		while(n>=3)
		{
			sum+=n;
			n/=2;
		}
		
		cout<<sum<<endl;
	}
	return 0;
}
