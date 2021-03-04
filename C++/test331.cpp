#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long a,b,c;
		
		cin>>a>>b>>c;
		
		long long val1=-1,val2=-1;
		
		if(a<c)
		{
			val1=1;
		}
		
		if(b*a>c)
			val2=b;
			
		cout<<val1<<' '<<val2<<endl;
	}
	return 0;
}
