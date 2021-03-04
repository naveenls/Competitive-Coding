#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxN=2000;

int arr[maxN][maxN];

int main(){
    
    cin>>n>>m;
    
    int k;
    cin>>k;
    memset(arr,-1,sizeof(arr));
    int u,v;
    
    queue<pair<int,int> > q;
    
    for(int i=0;i<k;i++)
    {
    	cin>>u>>v,u--,v--;
    	arr[u][v]=0;
    	q.push({u,v});
	}
	
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
				
		int a=p.first;
		int b=p.second;
		
		if(a+1<n && arr[a+1][b]==-1)
		{
			arr[a+1][b]=arr[a][b]+1;
			q.push({a+1,b});
		}
		if(a-1>=0 && arr[a-1][b]==-1)
		{
			arr[a-1][b]=arr[a][b]+1;
			q.push({a-1,b});
		}
		if(b+1<m && arr[a][b+1]==-1)
		{
			arr[a][b+1]=arr[a][b]+1;
			q.push({a,b+1});
		}
		if(b-1>=0 && arr[a][b-1]==-1)
		{
			arr[a][b-1]=arr[a][b]+1;
			q.push({a,b-1});
		}
	}
	int max=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			//cout<<arr[i][j]<<' ';
			if(arr[i][j]>max)
			{
				max=arr[i][j];
				u=i+1,v=j+1;
			}
		}
		//cout<<endl;
	}
	cout<<u<<' '<<v<<endl;
    return 0;
}
