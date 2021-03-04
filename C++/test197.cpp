#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		mp[arr[i]]++;
	}
	
	int ma=0;
	int val;
	
	for(auto itr=mp.begin();itr!=mp.end();itr++)
	{
		if(ma<itr->second)
		{
			ma=itr->second;
			val=itr->first;
		}
	}
	
	bool flag[n];
	for(int i=0;i<n;i++)
	{
		flag[i]=(arr[i]==val);
	}
	
	int ind=-1;
	for(int i=0;i<n;i++)
	{
		if(flag[i])
		{
			ind=i;
			break;
		}
	}
		
	vector<pair<int,int> > v;
	vector<int> type;
	
	for(int i=ind+1;i<n;i++)
	{
		if(!flag[i])
		{
			//Point p=new Point(i, i-1);
			v.push_back({i,i-1});
			
			if(arr[i]>arr[i-1])
			{	
				type.push_back(2);	
			}
			else
			{
				type.push_back(1);
			}
			arr[i]=arr[i-1];
		}
	}
	
	for(int i=ind-1;i>=0;i--)
	{
		if(!flag[i])
		{
			//Point p=new Point(i, i+1);
			v.push_back({i,i+1});
			
			if(arr[i]>arr[i+1])
			{	
				type.push_back(2);	
			}
			else
			{
				type.push_back(1);
			}
			arr[i]=arr[i+1];
		}
	}
	cout<<type.size()<<endl;
	for(int i=0;i<type.size();i++)
	{
		cout<<type[i]<<' '<<v[i].first+1<<' '<<v[i].second+1<<endl;
	}
	return 0;
}
