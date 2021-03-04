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
		
		bool flag[n]={0};
		
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]==i+1)
				flag[i]=1;
		}
		
		if(count(flag,flag+n,1)==n)
		{
			cout<<0<<endl;
		}
		else
		{
			int f1=0;
			
			for(int i=0;i<n;i++)
			{
				if(flag[i]==0)
				{
					if(f1==0)
					{
						f1=1;
					}
					else if(f1==2)
					{
						f1=3;
					}
				}
				else
				{
					if(f1==1)
					{
						f1=2;
					}
				}
			}
			
			if(f1==3)
			{
				cout<<2<<endl;
			}
			else
			{
				cout<<1<<endl;
			}
		}
	}
	return 0;
}
