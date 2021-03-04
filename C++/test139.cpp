#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+1;

vector<int> arr[maxN];


void nos(int a,int y,int i)
{
	set<int> divisor; 
	for(int i=1;i*i<=a;i++)
	{
		if(a%i==0)
		{
			divisor.insert(i);
			divisor.insert(a/i);
		}
	}
	if(y==0)
	{
		cout<<divisor.size()<<endl;
	}
	else
	{
		int l=i-y;
		int r=i-1;
		
		int cnt=0;
		
		for(auto ele:divisor)
		{
			auto itr=upper_bound(arr[ele].begin(),arr[ele].end(),l-1);
			
			arr[ele].push_back(i);
			if(itr!=arr[ele].end() && *itr<=r)
			{
				cnt++;
			}	
		}
		cout<<divisor.size()-cnt<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		nos(x,y,i);
	}
	return 0;
}
