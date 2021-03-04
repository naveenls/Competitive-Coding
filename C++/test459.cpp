#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	int arr[n];
	vector<int> v[k];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
		v[i%k].push_back(arr[i]);
	}
	
	for(int i=0;i<k;i++)
	{	
		bool flag=0;
		int s=-1;
		
		vector<pair<int,int> > range;
		
		int prev=-2*1e9;
		
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j]!='?')
			{
				if(v[i][j]<=prev)
				{
					cout<<"Incorrect sequence"<<endl;
					return 0;
				}
				prev=v[i][j];
			}
			
			if(flag)
			{
				if(v[i][j]!='?')
				{
					range.push_back({s,j});
					s=j;
					flag=0;
				}
			}
			else
			{
				if(v[i][j]!='?')
				{
					s=j;
				}
				else
				{
					flag=1;
				}
			}
			
			if(flag)
			{
				range.push_back({s,v[i].size()});
			}
		}
		
		for(auto ele:range)
		{
			int st=-2*1e9,en=2*1e9;
			
			if(ele.first>-1)
			{
				st=v[i][ele.first];
			}
			if(ele.second<v[i].size())
			{
				en=v[i][ele.second];
			}
			
			int len=ele.second-ele.first+1;
			
			if(en-st-1<len)
			{
				cout<<"Incorrect sequence"<<endl;
				return 0;
			}
			
			if(en<=0)
			{
				for(int k=ele.second-1;k>ele.first;k--)
				{
					v[i][k]=v[i][k+1]-1;
				}
			}
			else if(st>=0)
			{
				for(int k=ele.first+1;k<ele.second;k++)
				{
					v[i][k]=v[i-1][k]+1;
				}
			}
		}	
	}
	return 0;
}
