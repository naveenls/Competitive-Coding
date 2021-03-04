#include<bits/stdc++.h>
using namespace std;


int main()
{
	string s;
	cin>>s;
	
	reverse(s.begin(),s.end());
	
	bool DP2[s.size()];
	bool DP3[s.size()];
	
	for(int i=0;i<s.size();i++)
	{
		if(i<1)
		{
			DP2[i]=false;
			DP3[i]=false;	
		}
		else if(i==1)
		{
			DP2[i]=true;
			DP3[i]=false;
		}
		else if(i==2)
		{
			DP2[i]=false;
			DP3[i]=true;
		}
		else
		{
			DP2[i]=DP3[i-2] || (DP2[i-2] && s.substr(i-1,2)!=s.substr(i-3,2));
			DP3[i]=DP2[i-3] || (DP3[i-3] && s.substr(i-2,3)!=s.substr(i-5,3));
		}
	}
	set<string> ss;
	
	for(int i=0;i<s.size()-5;i++)
	{
		if(DP2[i])
			ss.insert(s.substr(i-1,2));
		if(DP3[i])
			ss.insert(s.substr(i-2,3));
	}
	
	set<string> ss1;
	for(auto ele:ss)
	{
		reverse(ele.begin(),ele.end());
		ss1.insert(ele);
	}

	cout<<ss.size()<<endl;
	for(auto ele:ss1)
		cout<<ele<<endl;	
	return 0;
}
