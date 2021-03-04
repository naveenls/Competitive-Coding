#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		set<int> s;
		int a;
		
		for(int i=0;i<n;i++)
		{
			cin>>a;
			s.insert(a);	
		}
		
		int val=-1;
		
		for(int i=0;i<m;i++)
		{
			cin>>a;
			
			if(s.find(a)!=s.end())
			{
				val=a;
			}
		}	
		
		if(val==-1)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<1<<' '<<val<<endl;
		}
	}	
	
	return 0;
}
