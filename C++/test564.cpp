#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		if(k>n)
		{
			cout<<k-n<<endl;
		}
		else
		{
			if((k+n)%2)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
