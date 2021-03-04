#include<bits/stdc++.h>
using namespace std;

const int maxM=1e5;

int cnt[maxM]={0};
int x[maxM],y[maxM];
long long ans[maxM];

set<int> s;
map<pair<int,int>,int > mp;

int dir[3]={-1,0,1};

bool check(int i)
{
    if(mp.find({x[i],y[i]})==mp.end())
    {
        return false;
    }
    for(int j=0;j<3;j++)
    {
        auto itr=mp.find({x[i]+dir[j],y[i]+1});
        
        if(itr!=mp.end())
        {
            if(cnt[itr->second]==1)
                return false;
        }
    }
    
    return true;
}

void remove(int i)
{
    mp.erase({x[i],y[i]});
    
	for(int j=0;j<3;j++)
    {
        auto itr=mp.find({x[i]+dir[j],y[i]+1});
        
        if(itr!=mp.end())
        {
            cnt[itr->second]--;
            
            int ind=itr->second;
            
            for(int k=0;k<3;k++)
            {
                auto it=mp.find({x[ind]+dir[k],y[ind]-1});
                
                if(it!=mp.end())
                {
                    if(!check(it->second))
                    {
                        if(s.find(it->second)!=s.end())
                            s.erase(it->second);
                    }
                }
            }
        }
    }
    
    for(int j=0;j<3;j++)
    {
        auto itr=mp.find({x[i]+dir[j],y[i]-1});
        
        if(itr!=mp.end())
        {
            if(check(itr->second))
            {
                s.insert(itr->second);
            }
        }
    }
}

long long mod=1e9+7;

int main()
{
	int m;
	cin>>m;
	
	for(int i=0;i<m;i++)
	{
		cin>>x[i]>>y[i];
		mp[{x[i],y[i]}]=i;
	}
	
	for(int i=0;i<m;i++)
	{
		if(y[i]!=0)
		{
			if(mp.find({x[i],y[i]-1})!=mp.end())
			{
				cnt[i]++;
			}
			if(mp.find({x[i]-1,y[i]-1})!=mp.end())
			{
				cnt[i]++;
			}
			if(mp.find({x[i]+1,y[i]-1})!=mp.end())
			{
				cnt[i]++;
			}
		}
	}
	
	for(int i=0;i<m;i++)
	{
		if(check(i))
		{
			s.insert(i);
		}
	}
	
	bool flag=0;
	
	for(int j=0;j<m;j++)
	{
		if(flag==0)
		{
			ans[j]=*s.rbegin();
			s.erase(*s.rbegin());
			remove(ans[j]);
		}	
		else
		{
			ans[j]=*s.begin();
			s.erase(s.begin());
			remove(ans[j]);
		}
		flag = flag^true;
	}

	long long f_ans=0;
	long long prod=1;
	long long mul=m;
	
	for(int i=m-1;i>=0;i--)
	{
		cout<<ans[i]<<' ';
		f_ans=(f_ans+prod*ans[i]%mod)%mod;
		prod=(prod*mul)%mod;
	}
	cout<<endl;
	cout<<f_ans<<endl;
	return 0;
}
