#include<bits/stdc++.h>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		set< pair < pair<int,int> , pair<int,int> > > ss;
		int x=0,y=0;
		int ans=0;
		for(int i=0;i<s.size();i++)
		{
			int x1,y1;
			if(s[i]=='N')
			{
				x1=x;
				y1=y+1;
			}
			else if(s[i]=='S')
			{
				x1=x;
				y1=y-1;
			}
			else if(s[i]=='E')
			{
				x1=x+1;
				y1=y;
			}
			else
			{
				x1=x-1;
				y1=1;
			}
			if(s.find({{x,y},{x1,y1}})!=s.end() || s.find({{x1,y1},{x,y}})!=s.end())
			{
				ans++;
			}
			else
			{
				s.insert({{x,y},{x1,y1}});
				ans+=5;
			}
		}
		cout<<ans<<endl;
		
	}
}
