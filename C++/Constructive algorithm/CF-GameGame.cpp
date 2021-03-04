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
		
		int cnt[30]={0};
		
		int a;

		for(int i=0;i<n;i++)
		{
			cin>>a;
			for(int j=0;j<30;j++)
			{
				cnt[j]+=a%2;
				a/=2;
			}
		}
		
		int res=0;
		
		for(int j=29;j>=0;j--)
		{
			if(cnt[j]%2)
			{
				int x=cnt[j];
				int y=n-cnt[j];
				
				if(x%4==3 && y%2==0)
				{
					res=2;
				}
				else
				{
					res=1;
				}
				break;
			}
		}
		
		switch(res)
		{
			case 0:
				cout<<"DRAW"<<endl;
				break;
			case 1:
				cout<<"WIN"<<endl;
				break;
			case 2:
				cout<<"LOSE"<<endl;
				break;
		}
	}
	return 0;
}
