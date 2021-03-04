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
		vector<int> ans;
		
		int a;
		for(int i=0;i<2*n;i++)
		{
			cin>>a;
			if(s.find(a)==s.end())
			{
				ans.push_back(a);
				s.insert(a);
			}
		}
		
		for(auto ele:ans)
		{
			cout<<ele<<' ';
		}
		cout<<endl;
		
	}
	return 0;
}
