#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	long long k,p;
	cin>>k>>p;
	
	long long arr[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	multiset<long long> rows;
	multiset<long long> cols;
	
	long long row_dec=0;
	long long col_dec=0;
	
	for(int i=0;i<n;i++)
	{
		long long val=0;
		for(int j=0;j<m;j++)
			val+=arr[i][j];
			
		rows.insert(val);
	}
	
	for(int j=0;j<m;++j)
	{
		long long val=0;
		for(int i=0;i<n;i++)
			val+=arr[i][j];
			
		cols.insert(val);
	}
	long long ans=0;
	while(k--)
	{
		auto itr1=rows.rbegin();
		auto itr2=cols.rbegin();
		
		if(*itr1-row_dec>*itr2-col_dec)
		{
			long long val=*itr1-row_dec;
			rows.erase(rows.find(*itr1));
			ans+=val;
			col_dec+=p;
			
			rows.insert(val-m*p);
		}
		else
		{
			long long val=*itr2-col_dec;
			cols.erase(cols.find(*itr2));
			ans+=val;
			row_dec+=p;
			
			cols.insert(val-n*p);
		}
		//cout<<ans<<endl;
	}

	cout<<ans<<endl;
	return 0;
}
