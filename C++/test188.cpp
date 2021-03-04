#include<bits/stdc++.h>
using namespace std;

int main()
{
	long double n,w,m;
	cin>>n>>w>>m;
	
	if(m<=n)
	{
		cout<<"YES"<<endl;
		
		long double cap=(n*w)/m;
		
		long double arr[(int)m+1]={0};
		vector<pair<int,long double> > ans[(int)m+1];
		
		int j=1;
		
		for(int i=1;i<=n;i++)
		{
			ans[j].push_back({i,min(w,cap-arr[j])});

			long double rem=w-min(w,cap-arr[j]);
			arr[j]+=min(w,cap-arr[j]);
			//cout<<j<<' '<<arr[j]<<endl;
			if(arr[j]==cap)
			{					
				j++;
				
				if(j>m)
					break;
					
				arr[j]+=rem;
				//cout<<rem<<endl;
				if(rem)
					ans[j].push_back({i,rem});
			}
		
		}
		for(int i=1;i<=m;i++)
		{
			for(auto ele:ans[i])
			{
				cout<<ele.first<<' '<<fixed<<setprecision(10)<<ele.second<<' ';
			}
			cout<<endl;
		}
	}
	else if(m<=2*n)
	{
		if((int)n%(int)(m-n))
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			long double cap=(n*w)/m;
			
			vector<pair<int,long double> > ans[(int)m+1];
			for(int i=1;i<=n;i++)
			{
				ans[i].push_back({i,cap});
			}
			
			for(int i=0;i<n;i++)
			{
				ans[(int)n+1+(int)i%(int)(m-n)].push_back({i+1,w-cap});
			}
			
			for(int i=1;i<=m;i++)
			{
				for(auto ele:ans[i])
				{
					cout<<ele.first<<' '<<fixed<<setprecision(10)<<ele.second<<' ';
				}
				cout<<endl;
			}
		}
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
