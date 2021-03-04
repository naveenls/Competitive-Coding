#include<bits/stdc++.h>
using namespace std;

multiset<int> adj[26];

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
        }            
        else 
		{
            temp.pop_back();             
            result.push_back(u); 
        }
    }
    return result; 
}

bool check_cycle(int n)
{
	int val1=-1;
	int val2=-1;
	
	int cnt1=0;
	int cnt2=0;
	
	int inD[26]={0};
	int outD[26]={0};
	
	for(int i=0;i<26;i++)
	{
		for(auto ele:adj[i])
		{
			outD[i]++;
			inD[ele]++;
		}
	}
	
	int valid;
	for(int i=0;i<26;i++)
	{
		if(inD[i]==outD[i])
		{
			if(outD[i])
				valid=i;
		}
		else if(inD[i]+1==outD[i])
		{
			cnt1++;
			if(val1==-1)
			{
				val1=i;
			}
		}
		else if(inD[i]==outD[i]+1)
		{
			cnt2++;
			if(val2==-1)
			{
				val2=i;
			}
		}
		else
		{
			return false;
		}
	}
	
	if(cnt1!=cnt2)
	{
		return false;
	}
	else if(cnt1>1)
	{
		return false;
	}
	
	vector<int> cycle;
	
	if(cnt1)
	{
		cycle=find_cycle(val1);
	}
	else
	{
		cycle=find_cycle(valid);
	}
	
	return cycle.size()==n+1;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		for(int i=0;i<26;i++)
		{
			adj[i].clear();
		}
		
		int n;
		cin>>n;
		
		string temp;
		
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			adj[temp[0]-'a'].insert(temp[temp.size()-1]-'a');
		}
		
		if(!check_cycle(n))
		{
			cout<<"The door cannot be opened."<<endl;
		}
		else
		{
			cout<<"Ordering is possible."<<endl;
		}
	}
	return 0;
}
