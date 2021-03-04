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
		string a;
		string b;
		cin>>a>>b;
		
		vector<int> in[26];
		vector<int> f[26];
		
		for(int i=0;i<n;i++)
		{
			in[a[i]-'a'].push_back(i);
			f[b[i]-'a'].push_back(i);
		}
		bool flag=0;
		vector<vector<int> > ans;
		for(int i=25;i>=0;i--)
		{
			vector<int> poss;
			for(auto j:f[i])
			{
				if(a[j]-'a'<i)
				{
					flag=1;
					break;
				}
				else if(a[j]-'a'!=i)
				{
					poss.push_back(j);
				}
			}
			if(flag)
			{
				break;
			}
			if(poss.size() && !in[i].size())
			{
				flag=1;
				break;
			}
			if(poss.size())
			{
				poss.push_back(in[i][0]);
				sort(poss.begin(),poss.end());
				ans.push_back(poss);
			}
		}
		if(flag)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<ans.size()<<endl;
			for(int i=0;i<ans.size();i++)
			{
				cout<<ans[i].size()<<' ';
				for(auto ele: ans[i])
				{
					cout<<ele<<' ';
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
