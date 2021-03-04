#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	
	int ans[a1+a2];
	
	if(a3==a4)
	{
		if(a1<a3 || a2<a4 || a1==a3 && a2==a4)
		{
			cout<<-1<<endl;
			return 0;	
		}	
		
		if(a1>a3)
		{
			int len=2*a3+1;
			
			int cnt4=a1-a3-1;
			int cnt7=a2-a4;
			
			int ind=0;
			while(cnt4--)
			{
				ans[ind]=4;
				ind++;
			}
			bool flag=0;
			for(int i=0;i<len-1;i++)
			{
				if(flag==0)
				{
					ans[ind]=4;
					flag=1;
				}	
				else
				{
					ans[ind]=7;
					flag=0;
				}
				ind++;
			}
			
			while(cnt7--)
			{
				ans[ind]=7;
				ind++;
			}
			ans[ind]=4;
									
		}
		else
		{
			int len=2*a3+1;
			
			int cnt4=a1-a3;
			int cnt7=a2-a4-1;
			
			int ind=0;
			
			ans[0]=7;
			ind++;
			
			while(cnt4--)
			{
				ans[ind]=4;
				ind++;
			}
			
			bool flag=0;
			
			for(int i=1;i<len;i++)
			{
				if(flag==0)
				{
					ans[ind]=4;
					flag=1;
				}	
				else
				{
					ans[ind]=7;
					flag=0;
				}
				ind++;
			}
			
			while(cnt7--)
			{
				ans[ind]=7;
				ind++;
			}
		}
		
		for(int i=0;i<a1+a2;i++)
		{
			cout<<ans[i];
		}
		cout<<endl;
	}
	else if(a3==a4+1)
	{
		if(a1<a3 || a2<a3)
		{
			cout<<-1<<endl;
			return 0;	
		}
		
		int len=2*a3;
			
		int cnt4=a1-a3;
		int cnt7=a2-a3;
		
		int ind=0;
		while(cnt4--)
		{
			ans[ind]=4;
			ind++;
		}
		bool flag=0;
		for(int i=0;i<len;i++)
		{
			if(flag==0)
			{
				ans[ind]=4;
				flag=1;
			}	
			else
			{
				ans[ind]=7;
				flag=0;
			}
			ind++;
		}
		
		while(cnt7--)
		{
			ans[ind]=7;
			ind++;
		}
		
		for(int i=0;i<a1+a2;i++)
		{
			cout<<ans[i];
		}
		cout<<endl;
				
	}
	else if(a3+1==a4)
	{
		if(a1<a4 || a2<a4)
		{
			cout<<-1<<endl;
			return 0;	
		}
		
		int len=2*a4;
			
		int cnt4=a1-a4;
		int cnt7=a2-a4;
		
		int ind=0;
		ans[0]=7;
		ind++;
		
		while(cnt4--)
		{
			ans[ind]=4;
			ind++;
		}
		
		bool flag=0;
		for(int i=1;i<len-1;i++)
		{
			if(flag==0)
			{
				ans[ind]=4;
				flag=1;
			}	
			else
			{
				ans[ind]=7;
				flag=0;
			}
			ind++;
		}
		
		while(cnt7--)
		{
			ans[ind]=7;
			ind++;
		}
		
		ans[ind]=4;
		
		for(int i=0;i<a1+a2;i++)
		{
			cout<<ans[i];
		}
		cout<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
	
}
