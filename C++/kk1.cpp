#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		
		if(a>b)
			swap(a,b);
			
		int x=b-a;
		
		if(x>a)
		{
			cout<<a<<endl;	
		}
		else
		{
			a-=x;
			b-=2*x;
			
			int ans=a/3+b/3;
			
			a=a%3;
			if(a==2)
				ans++;
				
			cout<<ans+x<<endl;
		}
	}
	return 0;
}
