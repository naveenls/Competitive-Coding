#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a,b;
	cin>>a>>b;
	
	int arr[n];
	
	map<int,int> mp;
	
	for(int i=0;i<n;i++)
		cin>>arr[i],mp[arr[i]]=1;
	
	queue<int> q;
	
	for(int i=0;i<n;i++)
	{
		if(!mp[a-arr[i]])
		{
			q.push(arr[i]);
		}
	}
	
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		
		if(!mp[b-x])
		{
			cout<<"NO"<<endl;
			return 0;
		}
		
		mp[x]=2;
		if(mp[b-x]==1)
		{
			mp[b-x]=2;
			
			if(mp[a+x-b]==1)
			{
				q.push(a+x-b);
			}
		}
	}
	
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<mp[arr[i]]-1<<' ';
	}
	return 0;
}
