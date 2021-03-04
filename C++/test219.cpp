#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5+10;

map<int,int> mp;
map<int,int> inv_mp;

multiset<int> adj[maxN]; 
  
vector<int> find_cycle(int src) 
{
   	vector<int> temp; 
	temp.push_back(src);
    vector<int> result;
    
    while (temp.size()) 
	{
        int u = temp.back();
        if (adj[u].size())
		{
            int v = *adj[u].begin();
            temp.push_back(v); 
            adj[u].erase(adj[u].begin()); 
	    	adj[v].erase(adj[v].find(u));
        }            
        else 
		{
            temp.pop_back();             
            result.push_back(u); 
        }
    }
    return result; 
}

void find_ans(int n) {
	
	int val1=-1;
	int val2=-1;
	
	int valid;
	
    for (int i = 0; i < maxN; ++i)
	{		
		if(adj[i].size())
			valid=i; 
		
		if(adj[i].size()%2)
		{
			if(val1==-1)
			{
				val1=i;
			}
			else if(val2==i)
			{
				val2=i;
			}
			else
			{
				cout<<-1<<endl;
				//cout<<"hi"<<endl;
				return;
			}
		}
    }
	
	
    if(val1!=-1 && val2==-1)
    {
    	cout<<-1<<endl;
    	//cout<<"hi"<<endl;
		return ;
	}
	vector<int> cycle;
	if(val1!=-1)
	{
		cycle=find_cycle(val1);
	}
	else
	{
		cycle=find_cycle(valid);
	}  
	//cout<<cycle.size()<<endl;
	if (cycle.size() == n+1)
	{
		for(int i=1;i<cycle.size();i++)
		{
			cout<<inv_mp[cycle[i]]<<' ';
		}
	}
	else
	{
		cout<<-1<<endl;
	}    
}

int main()
{
	int n;
	cin>>n;
	
	int b[n-1],c[n-1];
	
	for(int i=0;i<n-1;i++)
		cin>>b[i];
		
	for(int i=0;i<n-1;i++)
		cin>>c[i];
		
	for(int i=0;i<n-1;i++)
	{
		if(b[i]>c[i])
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	
	int cnt=1;
	for(int i=0;i<n-1;i++)
	{
		if(mp.find(b[i])==mp.end())
		{
			mp[b[i]]=cnt;
			cnt++;
		}
		if(mp.find(c[i])==mp.end())
		{
			mp[c[i]]=cnt;
			cnt++;
		}
	}
	for(auto ele:mp)
	{
		inv_mp[ele.second]=ele.first;
	}
	
	for(int i=0;i<n-1;i++)
	{
		//cout<<mp[b[i]]<<' '<<mp[c[i]]<<endl;
		adj[mp[b[i]]].insert(mp[c[i]]);
		adj[mp[b[i]]].insert(mp[c[i]]);
	}
	find_ans(n);
	return 0;
}
