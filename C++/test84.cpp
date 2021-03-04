#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6+1;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    set<int> s;
    vector<int> v[maxN];
    vector<int> distinct;
    
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	v[arr[i]].push_back(i);
    	
    	if(s.find(arr[i])==s.end())
    	{
    		s.insert(arr[i]);
    		distinct.push_back(arr[i]);
		}
	}
	
	int ans=0;
	for(int i=0;i<distinct.size();i++)
	{
		ans=max(ans,(int)v[distinct[i]].size());
		for(int j=i+1;j<distinct.size();j++)
		{
			int a=distinct[i],b=distinct[j];
			int type;
			
			int cnt=1;
			
			if(v[a][0]<v[b][0])
			{
				type=1;
			}
			else
			{
				type=2;
			}
			
			int ind1=0,ind2=0;
			while(ind1<v[a].size() && ind2<v[b].size())
			{
				if(v[a][ind1]<v[b][ind2])
				{
					if(type==2)
					{
						type=1;
						cnt++;
					}
					ind1++;
				}
				else
				{
					if(type==1)
					{
						type=2;
						cnt++;
					}
					ind2++;
				}
			}
			if(ind1<v[a].size())
			{
				if(type==2)
				{
					cnt++;
				}
			}
			if(ind2<v[b].size())
			{
				if(type==1)
				{
					cnt++;
				}
			}
			ans=max(ans,cnt);
		}
	}
    return 0;
}
