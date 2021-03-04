#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<pair<int,int> > ans;
	
	if(n%2==0)
	{
		ans.push_back({0,0});
		
		int start=1;
		while(n)
		{
			ans.push_back({0,start});
			ans.push_back({0,start+1});
			ans.push_back({-1,start+1});
			ans.push_back({1,start+1});
			ans.push_back({0,start+2});
			ans.push_back({-1,start+2});
			ans.push_back({1,start+2});
			start+=3;
			n-=2;
		}
		ans.push_back({0,start});
		ans.push_back({0,start+1});
		
		ans.push_back({1,start+1});
		ans.push_back({2,start+1});
		ans.push_back({3,start+1});
		
		ans.push_back({1,0});
		ans.push_back({2,0});
		ans.push_back({3,0});
		
		for(int i=1;i<=start;i++)
		{
			ans.push_back({3,i});
		}
	}
	else
	{
		n--;
		
		ans.push_back({0,0});
		
		int start=1;
		while(n)
		{
			ans.push_back({0,start});
			ans.push_back({0,start+1});
			ans.push_back({-1,start+1});
			ans.push_back({1,start+1});
			ans.push_back({0,start+2});
			ans.push_back({-1,start+2});
			ans.push_back({1,start+2});
			start+=3;
			n-=2;
		}
		ans.push_back({0,start});
		ans.push_back({0,start+1});
		
		ans.push_back({1,start+1});
		ans.push_back({2,start+1});
		ans.push_back({3,start+1});
		
		ans.push_back({1,0});
		ans.push_back({2,0});
		ans.push_back({3,0});
		
		for(int i=1;i<=start;i++)
		{
			ans.push_back({3,i});
		}
		
		start++;
		ans.push_back({0,start+1});
		ans.push_back({0,start+2});
		
		ans.push_back({-2,start+1});
		ans.push_back({-2,start+2});
		ans.push_back({-2,start});
		
		ans.push_back({-1,start});
		ans.push_back({-1,start+2});
	}
	cout<<ans.size()<<endl;
	for(auto ele:ans)
	{
		cout<<ele.first<<' '<<ele.second<<endl;
	}
	return 0;
}
