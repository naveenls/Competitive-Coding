#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > ans;

void b_search(int r,int n)
{
	int l=1,r_=n;
	
	int val;
	while(l<r_)
	{
		int mid=(l+r_)/2;
		
		cout<<'?'<<' '<<r<<' '<<l<<' '<<r<<' '<<mid<<endl;
		cout.flush();
		cin>>val;
		
		if(val%2)
		{
			r_=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	ans.push_back({r,l});
}

void b_search1(int c,int n)
{
	int l=1,r=n;
	
	int val;
	while(l<r)
	{
		int mid=(l+r)/2;
		
		cout<<'?'<<' '<<l<<' '<<c<<' '<<mid<<' '<<c<<endl;
		cout.flush();
		cin>>val;
		
		if(val%2)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	ans.push_back({l,c});
}
int main()
{
	int n;
	cin>>n;
	
	int row1=-1;
	int row2=-1;
	
	int val;
	for(int i=1;i<=n-1;i++)
	{
		cout<<'?'<<' '<<i<<' '<<1<<' '<<i<<' '<<n<<endl;
		cout.flush();
		cin>>val;
		
		if(val%2)
		{
			if(row1==-1)
			{
				row1=i;
			}
			else
			{
				row2=i;
				break;
			}
		}
	}
	
	if(row1!=-1 && row2==-1)
	{
		row2=n;
	}
	
	if(row1!=-1 && row2!=-1)
	{
		b_search(row1,n);
		b_search(row2,n);
		cout<<'!'<<' ';
		for(auto ele:ans)
		{
			cout<<ele.first<<' '<<ele.second<<' ';
		}
		cout.flush();
		return 0;
	}
	
	int col1=-1;
	int col2=-1;
	
	for(int i=1;i<=n-1;i++)
	{
		cout<<'?'<<' '<<1<<' '<<i<<' '<<n<<' '<<i<<endl;
		cout.flush();
		cin>>val;
		if(val%2)
		{
			if(col1==-1)
			{
				col1=i;
			}
			else
			{
				col2=i;
				break;
			}
		}
	}
	
	if(col1!=-1 && col2==-1)
	{
		col2=n;
	}
	
	b_search1(col1,n);
	b_search1(col2,n);
	cout<<'!'<<' ';
	for(auto ele:ans)
	{
		cout<<ele.first<<' '<<ele.second<<' ';
	}
	cout.flush();
	return 0;
}
