#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int ans=min(n+1,m+1);
	cout<<ans<<endl;
	for(int i=0;i<ans;i++)
	{
		cout<<n-i<<' '<<i<<endl;
	}	
	
	return 0;
}
