#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	int k;
	cin>>k;
	
	string arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	map<int,vector<pair<int,int> > > ans;
		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='.')
				continue;
			for(int dist=1;dist<n;dist++)
			{				
				if(i-dist<0 || i+dist>=n || j-dist<0 || j+dist>=m)
					break;
				
				if(arr[i-dist][j]=='*' && arr[i+dist][j]=='*' && arr[i][j-dist]=='*' && arr[i][j+dist]=='*')
				{
					ans[dist].push_back({i,j});
				}
			}
		}
	}
	int sum=0;
	
	int rad=-1;
	pair<int,int> pos;
	for(auto ele:ans)
	{
		sum+=ele.second.size();
		if(sum>=k)
		{
			sum-=ele.second.size();
			int aa=k-sum;
			rad=ele.first;
			pos=ele.second[aa-1];
			break;
		}
	}
	if(rad==-1)
	{
		cout<<-1<<endl;
	}
	else
	{
		pos.first++,pos.second++;
		cout<<pos.first<<' '<<pos.second<<endl;
		cout<<pos.first-rad<<' '<<pos.second<<endl;
		cout<<pos.first+rad<<' '<<pos.second<<endl;
		cout<<pos.first<<' '<<pos.second-rad<<endl;
		cout<<pos.first<<' '<<pos.second+rad<<endl;
	}
	
	return 0;
}
