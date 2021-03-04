#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int xor_val=0;
		
		int a;
		
		for(int i=0;i<n;i++)
		{
			cin>>a;
			xor_val=xor_val^a;
		}
		
		if(xor_val==0)
		{
			cout<<"First"<<endl;
		}
		else if(n%2)
		{
			cout<<"Second"<<endl;
		}
		else
		{
			cout<<"First"<<endl;
		}
	}
	return 0;
}
