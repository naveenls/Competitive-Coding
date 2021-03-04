#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5;
int n;

int vals[maxN];
vector<int> adj[maxN];
vector<int> adjR[maxN];
long long mod=1000000007 ;

void DFSUtil(int v, bool visited[],vector<int> &temp) 
{ 
    visited[v] = true; 
    temp.push_back(n);
  

    for (auto i = adjR[v].begin(); i != adjR[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited,temp); 
} 

void fillOrder(int v, bool visited[], stack<int> &Stack) 
{ 
    visited[v] = true; 
  
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            fillOrder(*i, visited, Stack); 
   
    Stack.push(v); 
} 

void find_scc() 
{
    stack<int> Stack; 
  
    bool *visited = new bool[n]; 
    for(int i = 0; i < n; i++) 
        visited[i] = false; 
  

    for(int i = 0; i < n; i++) 
        if(visited[i] == false) 
            fillOrder(i, visited, Stack); 
  
  
    for(int i = 0; i < n; i++) 
        visited[i] = false; 
  
  	long long ans=1;
  	long long min_val=0;
    while (Stack.empty() == false) 
    { 
        int v = Stack.top(); 
        Stack.pop(); 
  
        if (visited[v] == false) 
        { 
        	vector<int> temp;
            DFSUtil(v, visited,temp);
			
			int mi=2*1e9;
			for(auto i:temp)
			{
				mi=min(mi,vals[i]);	
			}
			long long cnt=0;
			for(auto i:temp)
			{
				if(vals[i]==mi)
					cnt++;
			}
			ans=(ans*cnt)%val;
			min_val+=mi;
        }
    }
    cout<<min_val<<' '<<ans<<endl;
} 

int main()
{
	int m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>vals[i];
	}
	cin>>m;
	int l,r;
	while(m--)
	{
		cin>>l>>r,l--,r--;
		adj[l].push_back(r);
		adjR[r].push_back(l);
	}
	
	return 0;
}
