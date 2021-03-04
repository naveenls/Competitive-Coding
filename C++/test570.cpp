#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	int a,b,c;
	
	cin>>n>>a>>b>>c;
	
	if(a+b-c>n)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else if(n!=2)
	{
		int extra=(n-(a+b-c));
		
		vector<int> ans;
		
		a-=c;
		b-=c;

	 	if(c==1)
		{
			if(a==0 && b==0)
			{
				if(n==1)
				{
					cout<<1<<endl;	
					return;
				}	
				else
				{
					cout<<"IMPOSSIBLE"<<endl;
					return;
				}
			}
			else
			{
				if(a==0)
				{
					while(c--)
					{
						ans.push_back(n);
					}
					while(extra--)
					{
						ans.push_back(1);
					}
					while(b--)
					{
						ans.push_back(2);
					}
				}
				else
				{
					while(a--)
					{
						ans.push_back(2);
					}
					while(extra--)
					{
						ans.push_back(1);
					}
					while(c--)
					{
						ans.push_back(n);
					}
					while(b--)
					{
						ans.push_back(2);
					}
				}
			}
		}
		else
		{
			while(a--)
			{
				ans.push_back(2);
			}
			
			ans.push_back(n);
			c--;
			
			while(extra--)
			{
				ans.push_back(1);
			}
			
			while(c--)
			{
				ans.push_back(n);
			}
			while(b--)
			{
				ans.push_back(2);
			}
		}
		
		
		for(auto ele:ans)
		{
			cout<<ele<<' ';
		}
		cout<<endl;
	}
	else
	{
		if(a==b && b==c && c==2)
		{
			cout<<"2 2"<<endl;
		}
		else if(a==2 && b==1 && c==1)
		{
			cout<<"1 2"<<endl;
		}
		else if(a==1 && b==2 && c==1)
		{
			cout<<"2 1"<<endl;
		}
		else
		{
			cout<<"IMPOSSIBLE"<<endl;
		}
	}
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
