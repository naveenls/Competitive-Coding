#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<1+(x2-x1)*(y2-y1)<<endl;
	}
	return 0;
}
