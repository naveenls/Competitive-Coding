#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5;
vector<int> adjD[maxN];
int col[maxN];

void topologicalSortUtil( int v, bool visited[], stack<int> &Stack) 
{ 
    visited[v] = true; 
  
    for (auto i = adjD[v].begin(); i != adjD[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 

    Stack.push(v); 
} 

void topologicalSort(int V,vector<int> &v) 
{ 
    stack<int> Stack; 
  
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    while (Stack.empty() == false) 
    { 
        v.push_back(Stack.top()); 
        Stack.pop(); 
    } 
}

bool check_cycle(int i)
{
	if(col[i]==0)
	{
		col[i]=1;
		
		bool has_cycle=false;
		for(auto ch:adjD[i])
		{

			has_cycle|=check_cycle(ch);
		}
		
		col[i]=2;
		
		return has_cycle;
	}
	else if(col[i]==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		for(int i=0;i<n;i++)
		{
			adjD[i].clear();
			col[i]=0;
		}
		
		int type,u,v;
		
		vector<pair<int,int> > ans;
		vector<pair<int,int> > v1;
		
		for(int i=0;i<m;i++)
		{
			cin>>type>>u>>v;
			u--,v--;
			
			if(type==1)
			{
				adjD[u].push_back(v);
				ans.push_back({u,v});
			}
			else
			{
				v1.push_back({u,v});
			}
		}
		
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			if(!col[i] && check_cycle(i))
			{
				cout<<"NO"<<endl;
				flag=1;
				break;
			}
		}
		
		if(flag)
		{
			continue;
		}
		
		vector<int> t_sort;
		topologicalSort(n,t_sort);
		
		int pos[n];
		for(int i=0;i<n;i++)
		{
			pos[t_sort[i]]=i;
		}
		
		cout<<"YES"<<endl;
		
		for(auto ele:v1)
		{
			if(pos[ele.first]>pos[ele.second])
			{
				ans.push_back({ele.second,ele.first});
			}
			else
			{
				ans.push_back({ele.first,ele.second});
			}
		}
		
		for(auto ele:ans)
		{
			cout<<ele.first+1<<" "<<ele.second+1<<endl;
		}
	}
	return 0;
}
