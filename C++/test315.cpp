#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	int x[m],y[m];
	
	set<int> count[n+1];
	
	for(int i=0;i<m;i++)
	{
		cin>>x[i]>>y[i];
		count[x[i]].insert(i);
		count[y[i]].insert(i);
	}
	
	vector<int> ans;
	
	set<int> s;
	
	bool flag[n+1]={0};
	
	for(int i=1;i<=n;i++)
	{
		if(count[i].size()<=arr[i])
		{
			s.insert(i);
			flag[i]=1;	
		}
	} 
	
	while(!s.empty())
	{
		set<int> new_val;
		
		for(auto ind:s)
		{
			for(auto ele:count[ind])
			{
				ans.push_back(ele);
				
				if(x[ele]==ind)
				{
					count[y[ele]].erase(ele);
					
					if(count[y[ele]].size()<=arr[y[ele]] && !flag[y[ele]])
					{
						new_val.insert(y[ele]);
					}
				}
				else
				{
					count[x[ele]].erase(ele);
					
					if(count[x[ele]].size()<=arr[x[ele]] && !flag[x[ele]])
					{
						new_val.insert(x[ele]);
					}
				}
			}
		}
		
		s.clear();
		for(auto ele:new_val)
		{
			s.insert(ele);
			flag[ele]=1;
		}
	}
	
	if(ans.size()!=m)
	{
		cout<<"DEAD"<<endl;
	}
	else
	{
		cout<<"ALIVE"<<endl;
		
		reverse(ans.begin(),ans.end());
		for(auto ele:ans)
			cout<<ele+1<<' ';
	}
	return 0;
}
