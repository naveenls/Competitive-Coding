#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		
		int odd=0;
		int even=0;
		
		int a;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			if(a%2)
				odd++;
			else
				even++;
		}
		bool flag=0;

		for(int i=1;i<=min(x,odd);i+=2)
		{
			if((x-i)<=even)
			{
				flag=1;
				break;
			}
		}
		
		if(flag)
		{
			cout<<"Yes"<<endl;	
		}	
		else
			cout<<"No"<<endl;
		
	}
	return 0;
}
