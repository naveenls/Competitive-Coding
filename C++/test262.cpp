#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	
	string s;
	cin>>s;
	
	int prev=-1;
	vector<pair<int,int> > seg;
	
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			int len=i-prev-1;
			if(len)
			{
				seg.push_back({len,i});
			}
			prev=i;
		}
	}
	if(n-prev-1)
	{
		seg.push_back({n-prev-1,n});
	}
	
	int min_try=0;
	for(auto ele:seg)
	{
		if(ele.first>=b)
		{
			min_try+=ele.first/b;
		}
	}
	cout<<min_try-a+1<<endl;
	
	int times=min_try-a+1;
	for(int i=0;i<seg.size();i++)
	{
		auto ele=seg[i];
		if(ele.first>=b)
		{
			int start=ele.second-b+1;
			
			int end=ele.second-ele.first+1;
			while(start>=end && times)
			{
				cout<<start<<' ';
				start-=b;
				times--;
			}
			if(!times)
				break;
		}
	}
	return 0;
}
