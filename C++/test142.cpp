#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<int> J_a;
	vector<int> J_d;
	
	string s;
	int a;
	
	for(int i=0;i<n;i++)
	{
		cin>>s;
		cin>>a;
		if(s=="ATK")
		{
			J_a.push_back(a);
		}
		else
			J_d.push_back(a);
	}
	
	vector<int> C(m);
	for(int i=0;i<m;i++)
	{
		cin>>C[i];
	}
	
	sort(J_a.begin(),J_a.end());
	sort(J_d.begin(),J_d.end(),greater<int> ());
	
	sort(C.begin(),C.end());
	
	int ans=0;

	auto itr=C.rbegin();
	auto itr1=J_a.begin();
	
	int cnt=0;
	
	while(itr!=C.rend() && itr1!=J_a.end())
	{
		if(*itr>=*itr1)
		{
			ans+=(*itr-*itr1);
			itr++;
			itr1++;
			cnt++;
		}
		else
			break;
	}
	
	if(J_a.size() && m>J_a.size() && C[0]>J_a[0] && C[m-1]>J_a[J_a.size()-1])
	{
		int temp=0;
		int i=m-1;
		
		int c=J_a.size();
		while(c)
		{
			temp+=C[i];
			i--;
			c--;
		}
		
		for(auto ele:J_a)
		{
			temp-=ele;
		}
		
		if(temp>ans)
		{
			ans=temp;
			cnt=J_a.size();
		}
	}
	while(cnt--)
	{
		C.pop_back();
	}
	
	int cnt1=0;
	
	for(auto ele:J_d)
	{
		if(!C.size())
			break;
			
		auto itr=upper_bound(C.begin(),C.end(),ele);
		if(itr!=C.end())
		{
			C.erase(itr);
			cnt1++;
		}
	}
	
	if(itr1==J_a.end() && cnt1==J_d.size())
	{
	//	cout<<"hi"<<endl;
		for(auto ele:C)
			ans+=ele;
	}
		
	cout<<ans<<endl;
	return 0;
}
