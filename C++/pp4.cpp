#include<bits/stdc++.h>

#define in(x) scanf("%d",&x)
#define inn(x,y) scanf("%d%d",&x,&y)
#define innn(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;
const int maxN=1e5+5;

int n,m,k;
vector<int> adj[maxN];
int depth[maxN],parent[maxN];

void DFS(int x)
{
    depth[x]=depth[parent[x]]+1;
    for(auto ch:adj[x]) 
	{
		if(ch!=parent[x])
		{
			//cout<<x<<' '<<depth[x]<<' '<<depth[ch]<<endl;
	        if(!depth[ch])
			{
	            parent[ch]=x;
	            DFS(ch);
	        }
			else if(depth[x]-depth[ch]+1<=k)
			{
	            cout<<2<<endl<<depth[x]-depth[ch]+1<<endl; 
	            while(x!=ch)
				{
	                cout<<x<<" "; 
	                x=parent[x];
	            }
	            cout<<ch<<endl;
	            exit(0);
	        }
		}
    }
}

void DFS1(int x)
{
    depth[x]=depth[parent[x]]+1;
    for(auto ch:adj[x]) 
	{
		if(ch!=parent[x])
		{
	        if(!depth[ch])
			{
	            parent[ch]=x;
	            DFS1(ch);
	        }
	        else
	        {
	        	cout<<1<<endl;
	        	int num=(k+1)/2;
	        	
	        	for(int i=0;i<num;i++)
	        	{
	        		cout<<x<<' ';
	        		x=parent[x];
	        		x=parent[x];
				}
				exit(0);
			}
		}
    }
}

int blue[maxN],vis[maxN];
vector<int> independentSet;

void getIndependentSet(int x)
{
    vis[x]=1;
    for(auto xx: adj[x]) if(!vis[xx]) getIndependentSet(xx);
    if(!blue[x]){
        independentSet.push_back(x);
        for(auto xx: adj[x])  
            blue[xx]=1;   
    }
}

int main(){
	
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
	{
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
	
	memset(depth,0,sizeof(depth));
	memset(parent,0,sizeof(parent));
	
    DFS(1);
    
    memset(depth,0,sizeof(depth));
	memset(parent,0,sizeof(parent));
	
	DFS1(1);
	
    getIndependentSet(1);
    cout<<"1\n";
    for(int i=0;i<k;i++) cout<<independentSet[i]<<" ";
    return 0;
}

