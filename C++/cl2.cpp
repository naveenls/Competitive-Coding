#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n;
		
		vector<int> v;
		
		int a;
		
		for(int i=0;i<n;i++)
		{
			cin>>a;
			v.push_back(a);
		}
		cin>>q;
		
		int x,y;
		for(int i=0;i<q;i++)
		{
			cin>>x>>y;
			
			auto itr=lower_bound(v.begin(),v.end(),x+y);
			
			if(itr==v.end())
			{
				cout<<n<<endl;
			}
			else
			{
				if(*itr==x+y)
				{
					cout<<-1<<endl;
				}
				else
				{
					cout<<itr-v.begin()<<endl;
				}
			}
		}
	}
	return 0;
}
