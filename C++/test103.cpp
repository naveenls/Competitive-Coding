#include <bits/stdc++.h>
#include <string>
using namespace std;
const int maxN=2500;
int n,m;

string arr[maxN];

vector<int> adj[maxN];

bool visited[maxN];
int disc[maxN];
int low[maxN];
int parent[maxN];
bool ap[maxN];

void APUtil(int u) 
{ 
    static int time = 0; 
  
    int children = 0;   
    visited[u] = true; 
  
    disc[u] = low[u] = ++time; 
  
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;

        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            APUtil(v); 

            low[u]  = min(low[u], low[v]); 

            if (parent[u] == -1 && children > 1) 
               ap[u] = true; 

            if (parent[u] != -1 && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
  
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
bool AP() 
{   
    for (int i = 0; i < n*m; i++) 
    { 
        parent[i] = -1; 
        visited[i] = false; 
        ap[i] = false; 
    } 

    for (int i = 0; i < n*m; i++) 
        if (visited[i] == false) 
            APUtil(i); 
  
    for (int i = 0; i < n*m; i++) 
        if (ap[i] == true) 
            return true;
            
    return false;
} 
int main() {
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='#')
			{
				cnt++;
				if(i+1<n && arr[i+1][j]=='#')
				{
					adj[i*m+j].push_back((i+1)*m+j);
				}
				if(j+1<m && arr[i][j+1]=='#')
				{
					adj[i*m+j].push_back(i*m+j+1);
				}
				if(i-1>=0 && arr[i-1][j]=='#')
				{
					adj[i*m+j].push_back((i-1)*m+j);
				}
				if(j-1>=0 && arr[i][j-1]=='#')
				{
					adj[i*m+j].push_back(i*m+j-1);
				}
			}
		}
	}
	if(cnt==1 || cnt==2)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(n*m<=3)
	{
		cout<<"1"<<endl;
		return 0;
	}
	if(AP())
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<2<<endl;
	}
	return 0;
}
