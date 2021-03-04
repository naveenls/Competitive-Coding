#include<bits/stdc++.h>
using namespace std;

void clear(stack<int> &s)
{
	while(!s.empty())
		s.pop();
}

long long ans=0;

void find_intersection(set<pair<int,int> > &arr1,set<pair<int,int> > &arr2) 
{ 
    auto i = arr1.begin(), j = arr2.begin(); 
  
    int n = arr1.size(), m = arr2.size(); 
   
    while (i!=arr1.end() && j!=arr2.end()) 
	{ 
        int l = max((*i).first, (*j).first); 
 
        int r = min((*i).second,(*j).second); 
  
        if (l <= r) 
    	{
    		long long len=r-l+1;
    		ans+=len*(len+1)/2;
    		
    		cout<<len<<endl;
		}
        if ((*i).second< (*j).second) 
            i++; 
        else
            j++; 
    } 
} 

int main()
{
	int n;
	cin>>n;
	
	int a[n],b[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<n;i++)
		cin>>b[i];
		
	int a_l[n],a_r[n];
	
	memset(a_l,-1,sizeof(a_l));
	memset(a_r,-1,sizeof(a_r));
	
	stack<int> s;
	
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && a[s.top()]<a[i])
		{
			a_r[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	
	clear(s);
	
	for(int i=n-1;i>=0;i--)
	{
		while(!s.empty() && a[s.top()]<a[i])
		{
			a_l[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	
	clear(s);
	
	int b_l[n],b_r[n];
	
	memset(b_l,-1,sizeof(b_l));
	memset(b_r,-1,sizeof(b_r));
	
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && b[s.top()]>b[i])
		{
			b_r[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	
	clear(s);
	
	for(int i=n-1;i>=0;i--)
	{
		while(!s.empty() && b[s.top()]>b[i])
		{
			b_l[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	
	map<int,set<pair<int,int> > > mp_a;
	map<int,set<pair<int,int> > > mp_b;
	
	for(int i=0;i<n;i++)
	{			
		if(a_r[i]==-1)
			a_r[i]=n;

		if(b_r[i]==-1)
			b_r[i]=n;
			
		a_l[i]++,b_l[i]++,a_r[i]--,b_r[i]--;
			
		mp_a[a[i]].insert({a_l[i],a_r[i]});
		mp_b[b[i]].insert({b_l[i],b_r[i]});
	}
	
	for(auto ele:mp_a)
	{
		if(mp_b.find(ele.first)!=mp_b.end())
		{
			find_intersection(ele.second,mp_b[ele.first]);
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
