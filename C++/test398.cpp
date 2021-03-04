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
		
		set<int> s;
		s.insert(0);
		
		for(int i=1;i<=sqrt(n);i++)
		{
			int temp=n/i;
			s.insert(n/temp);
			s.insert(n/i);
		}
		
		cout<<s.size()<<endl;
		for(auto ele:s)
		{
			cout<<ele<<' ';
		}
		cout<<endl;
	}
}
