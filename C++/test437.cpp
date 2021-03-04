#include<bits/stdc++.h>
using namespace std;

int find_par(int i,int par[])
{
	if(par[i]==-1)
		return -1;
		
	if(i==par[i])
		return i;
	par[i]=find_par(par[i],par);
	return par[i];
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		long long sum=0;
		
		int k[n];
		int r[n];
		int l[n];
		
		vector<int,int > > v;
		
		for(int i=0;i<n;i++)
		{
			cin>>k[i]>>l[i]>>r[i];
			k[i]--;
			
			v.push_back({l[i],i});
			v.push_back({r[i],i});
		}
		
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		
		bool flag[n]={0};
		
		int par[n];
		for(int i=0;i<n;i++)
		{
			par[i]=i;
		}
		
		int val[n]={0};
		
		vector<pair<int,int> > v_new;
		
		for(int i=0;i<n;i++)
		{
			int ind=v[i].second;
			
			if(!flag[ind])
			{
				if(l[ind]>=r[ind])
				{
					if(val[k[ind]]==0)
					{
						sum+=l[ind];
						val[k[ind]]=1;
						
						par[k[ind]]=k[ind]-1;
						
						flag[ind]=1;
					}
					else
					{
						int p=find_par(k[ind],par);
						
						if(p==-1)
						{
							v_new.push_back({r[ind],ind});
						}
						else
						{
							val[p]=1;
							sum+=l[ind];
							
							par[p]=p-1;
							flag[ind]=1;
						}
					}
				}
				else
				{
					v_new.push_back({r[ind],ind});
				}
			}			
		}
		
		sort(v_new.begin(),v_new.end());
		reverse(v_new.begin(),v_new.end());
		
		int start=n-1;
		
		for(auto ele:v_new)
		{
			if(k[ele.second]<start)
			{
				sum+=ele.first;
			}
			else
			{
				sum+=l[ele.second];
			}
			start--;
		}
		cout<<sum<<endl;
	}
}
