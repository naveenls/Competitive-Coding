#include<bits/stdc++.h>
using namespace std;

int find_mex(int arr[],int n)
{
	set<int> s;
	for(int i=0;i<n;i++)
	{
		s.insert(arr[i]);
	}
	int start=0;
	
	for(auto ele:s)
	{
		if(ele==start)
			start++;
		else
		{
			break;
		}
	}
	
	return start;
}

bool check(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
			return true;
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		int mex;
		
		vector<int> ans;

		while(check(arr,n))
		{
			mex=find_mex(arr,n);
			
			if(mex==n)
			{
				for(int i=0;i<n;i++)
				{
					if(arr[i]!=i)
					{
						ans.push_back(i);
						arr[i]=mex;
						break;	
					}
				}	
			}
			else
			{
				ans.push_back(mex);	
				arr[mex]=mex;
			}
		}
		
		cout<<ans.size()<<endl;
		for(auto ele:ans)
		{
			cout<<ele+1<<' ';
		}
		cout<<endl;
	}
	return 0;
}
