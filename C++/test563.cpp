#include<bits/stdc++.h>
using namespace std;

int h,w;
const int maxh=1e3;

string arr[maxh];
int val[maxh][maxh];

void dfs(int i,int j,int cnt)
{
	if(i>=h || i<0 || j>=w || j<0)
		return;
	
	if(arr[i][j]=='#' || val[i][j]!=-1)
		return;
		
//	cout<<i<<' '<<j<<' '<<cnt<<endl;
	
	val[i][j]=cnt;
	
	dfs(i+1,j,cnt);
	dfs(i-1,j,cnt);
	dfs(i,j+1,cnt);
	dfs(i,j-1,cnt);
}

int main()
{
	cin>>h>>w;
	
	int sx,sy;
	int ex,ey;
	
	cin>>sx>>sy;
	cin>>ex>>ey;
	
	sx--,sy--;
	ex--,ey--;
	
	memset(val,-1,sizeof(val));
	
	for(int i=0;i<h;i++)
	{
		cin>>arr[i];
	}
	
	int cnt=0;
	
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(val[i][j]==-1 && arr[i][j]=='.')
			{
				//cout<<i<<' '<<j<<endl;
				dfs(i,j,cnt++);
			}
		}
	}
	
	set<int> adj[cnt];
	int depth[cnt];
	memset(depth,-1,sizeof(depth));
	
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(arr[i][j]=='.')
			{
				int v1=val[i][j];
				
				for(int x=max(0,i-2);x<=min(h-1,i+2);x++)
				{
					for(int y=max(0,j-2);y<=min(w-1,j+2);y++)
					{
						int v2=val[x][y];
						
						if(v1!=v2)
						{
							adj[v1].insert(v2);
						}
					}
				}
			}
		}
	}
	
	queue<int> q;
	q.push(val[sx][sy]);
	depth[val[sx][sy]]=0;
	
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		
		for(int j:adj[v])
		{
			if(depth[j]==-1)
			{
				depth[j]=depth[v]+1;
				q.push(j);
			}
		}
	}
	
	cout<<depth[val[ex][ey]]<<endl;
	return 0;
}
