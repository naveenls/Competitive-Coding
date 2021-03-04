#include<bits/stdc++.h>
using namespace std;

int main()
{
	int h,w;
	cin>>h>>w;
	
	set<pair<int,int> > s;
	multiset<int> ms;
	
	int l[h],r[h];
	
	for(int i=0;i<h;i++)
	{
		cin>>l[i]>>r[i];
	}	
	
	for(int i=1;i<=w;i++)
	{
		s.insert({i,i});
		ms.insert(0);
	}
	
	for(int i=0;i<h;i++)
	{
      	if(s.size()==0)
        {
          	cout<<-1<<endl;
          	continue;
        }
      
		auto itr=s.lower_bound({l[i],0});
		vector<pair<int,int> > del;
		
		if(r[i]==w)
		{
			while(itr!=s.end() && itr->first<=r[i])
			{
				del.push_back(*itr);				
				++itr;
			}
		}
		else
		{
			int max_start=0;
			
			while(itr!=s.end() && itr->first<=r[i])
			{
				del.push_back(*itr);
			
				max_start=max(max_start,itr->second);
				
				++itr;
			}
			
          	if(max_start!=0)
            {
				s.insert({r[i]+1,max_start});
				ms.insert(r[i]+1-max_start);
            }
		}
		
      	
		for(auto ele:del)
		{
			s.erase(ele);
			ms.erase(ms.find(ele.first-ele.second));
		}
      
		if(ms.size())
		{
			cout<<*ms.begin() + i+1 <<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}
