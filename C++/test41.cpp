#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,g,b;
	cin>>r>>g>>b;
	if(r>g)
		swap(r,g);
	
	if(g>b)
	{
		swap(g,b);
		if(r>g)
			swap(r,g);
	}
	//cout<<r<<' '<<g<<' '<<b<<endl;
	int ans=r;
	b-=r;
	g-=r;
	int temp=min(g/3,b/3);
	ans+=2*temp;
	g=g%3;
	b-=temp*3;
	if(g)
		ans+=min(g,b/2);
	
	cout<<ans<<endl;
	//cout<<r+(b-r)/2<<endl;
}
