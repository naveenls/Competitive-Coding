#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 
typedef pair<int, int> iPair; 
const int maxN=100;

int arr[maxN];
int X[maxN];
int Y[maxN];

int n,d;

int distance(int i,int j)
{
	return d*abs(X[i]-X[j])+d*abs(Y[i]-Y[j]);
}

void shortestPath(int src) 
{ 

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

    vector<int> dist(n, INF); 
  
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 

    while (!pq.empty()) 
    {
        int u = pq.top().second; 
        pq.pop(); 
  
        for (int v = 0; v <n ; ++v) 
        { 
            if(v!=u)
            {
	            int weight = distance(u,v)-arr[u]; 
	  
	            if (dist[v] > dist[u] + weight) 
	            { 
	                dist[v] = dist[u] + weight; 
	                pq.push(make_pair(dist[v], v)); 
	            }
			}
        } 
    } 
  
   cout<<dist[n-1]<<endl;
} 

int main()
{
	cin>>n>>d;
	for(int i=1;i<n-1;i++)
	{
		cin>>arr[i];
	}
	arr[0]=0;
	arr[n-1]=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>X[i]>>Y[i];
	}
	shortestPath(0);
	return 0;
}
