#include <bits/stdc++.h>
using namespace std;

const int maxN=1e5;

vector<int> adj[maxN];
long long b[maxN];

long long DP[maxN][2][2];

void dfs(int i,int p)
{
    long long sum1=0;
    long long sum2=0;
    
    int num_ch=0;
    vector<int> child;
    
    for(auto ch:adj[i])
    {
        if(ch!=p)
        {
            num_ch++;
            child.push_back(ch);
            
            dfs(ch,i);
            
            sum1+=max(DP[ch][1][0],DP[ch][1][1]);
            sum2+=max(DP[ch][0][0],DP[ch][0][1]);
        }
    }
    
    DP[i][1][1]=DP[i][0][1]=b[i] + sum1;
    
    DP[i][1][0]=b[i] + sum1;
    
    if(num_ch==0)
    {
        DP[i][0][0]=0;
        return;
    }
    
    long long DPt[num_ch][2];
    
    DPt[0][0]=DP[child[0]][0][0];
    DPt[0][1]=b[i]+DP[child[0]][0][1];
    
    for(int j=1;j<num_ch;j++)
    {
        DPt[j][0]= DPt[j-1][0]+DP[child[j]][0][0];
        DPt[j][1]= max(DPt[j-1][1] + max(DP[child[j]][0][0],DP[child[j]][0][1]),b[i]+DPt[j-1][0]+DP[child[j]][0][1]);
    }
    
    DP[i][0][0]=max(DPt[num_ch-1][0],DPt[num_ch-1][1]);
}

void solve()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        adj[i].clear();
        cin>>b[i];
    }
    
    int u,v;
    
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        u--,v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0,-1);
    
    cout<<max(DP[0][0][0],DP[0][0][1])<<endl;
}
int main() {
	
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
	    cout<<"Case #"<<i<<": ";
	    solve();
	}
	return 0;
}

