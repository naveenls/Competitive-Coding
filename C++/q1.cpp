#include<bits/stdc++.h>
using namespace std;

bool check(int a,int b,int c,int d)
{
	if(a<0 || b<0 || c<0)
		return false;
		
	int cnt_odd=a%2+b%2+c%2+d%2;
	
	return cnt_odd<=1;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int r,g,b,w;
		cin>>r>>g>>b>>w;
		
		bool flag=check(r,g,b,w) || check(r-1,g-1,b-1,w+3);
		
		if(flag)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
		
	}
	return 0;
}
