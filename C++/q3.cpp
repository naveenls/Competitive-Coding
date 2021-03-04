#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int a[n];
	int b[m];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int j=0;j<m;j++)
	{
		cin>>b[j];
	}
	
	for(int num=0;num<512;num++)
	{
		bool flag=0;
		
		for(int i=0;i<n;i++)
		{
			bool ff=0;
			
			for(int j=0;j<m;j++)
			{
				int val=a[i]&b[j];
				
				if((val|num)<=num)
				{
					ff=1;
					break;
				}
			}
			
			if(!ff)
			{
				flag=1;
				break;
			}
		}
		
		if(!flag)
		{
			cout<<num<<endl;
			return 0;
		}
	}
	return 0;
}
