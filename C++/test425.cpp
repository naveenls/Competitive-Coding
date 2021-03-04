#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	set<int> a;
	set<int> b;
	
	for(int i=1;i<=n;i++)
	{
		b.insert(i);
	}
	int temp;
	int arr[n+1];
	
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		arr[i]=temp;
		
		if(temp==0)
		{
			a.insert(i);
		}
		else
		{
			b.erase(temp);
		}
	}
	
	vector<int> val;
	
	vector<int> v1;
	
	for(auto ele:a)
	{
		if(b.find(ele)!=b.end())
		{
			val.push_back(ele);
			b.erase(ele);
		}
		else
		{
			v1.push_back(ele);
		}
	}
	/*
	for(auto ele:val)
	{
		cout<<ele<<' ';
	}
	cout<<endl;*/
	if(val.size()==1)
	{
			
		arr[val[0]]=*b.begin();
		b.erase(*b.begin());
		
		b.insert(val[0]);
		
		int i=0;
	
		for(auto itr=b.begin();itr!=b.end();itr++)
		{
			arr[v1[i]]=*itr;
			i++;
		}
		
	}
	else
	{
		int i=0;
	
		for(auto itr=b.begin();itr!=b.end();itr++)
		{
			arr[v1[i]]=*itr;
			i++;
		}
		
		if(val.size())
		{
			for(int i=0;i<val.size();i++)
			{
				arr[val[i]]=val[(i+1)%val.size()];
			}
			
		}
	}
	
	
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<' ';
	}
	return 0;
}
