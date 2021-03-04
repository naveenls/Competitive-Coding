#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;
vector<int> adj[maxN];
int depth[maxN];
int child[maxN];

void topologicalSortUtil( int v, bool visited[], stack<int> &Stack) 
{ 
    visited[v] = true; 
   
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    Stack.push(v); 
} 
 
vector<int> sorted;

void topologicalSort(int n) 
{ 
    stack<int> Stack; 
  
    bool *visited = new bool[n]; 
    for (int i = 0; i < n; i++) 
        visited[i] = false; 
  
    for (int i = 0; i < n; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 

    while (Stack.empty() == false) 
    { 
        sorted.push_back(Stack.top()); 
        Stack.pop(); 
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	int u,v;
	
	set<int> head;
	set<int> tail;
	for(int i=0;i<n;i++)
	{
		head.insert(i);
		tail.insert(i);
		depth[i]=1;	
	}
		
	map<pair<int,int>,int > ss;
	
	for(int i=0;i<m;i++)
	{
		cin>>u>>v,u--,v--;
		
		ss[{u,v}]=i+1;
		
		adj[u].push_back(v);
		if(head.find(v)!=head.end())
			head.erase(v);	
		
		if(tail.find(u)!=tail.end())
			tail.erase(u);
	}	

	if(head.size()>1 || tail.size()>1)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	topologicalSort(n);
	
	reverse(sorted.begin(),sorted.end());
	
	depth[sorted[0]]=1;
	child[sorted[0]]=-1;
	
	for(int i=1;i<n;i++)
	{
		int v=sorted[i];
		
		for(auto ch:adj[v])
		{
			if(depth[v]<depth[ch]+1)
			{
				depth[v]=depth[ch]+1;
				child[v]=ch;	
			}
		}
	}
	if(depth[*head.begin()]!=n)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	int ta=*head.begin();
	
	int ma=0;
	
	while(child[ta]!=-1)
	{
		ma=max(ma,ss[{ta,child[ta]}]);
		ta=child[ta];
	}
	
	cout<<ma<<endl;
	return 0;
}
