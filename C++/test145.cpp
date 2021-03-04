const int maxN=2*1e5+10;

vector<int> adj[maxN];
int par[maxN];
int level[maxN];

const int k=19;

int LCA[maxN][k];
int n;

void dfs(int i,int p,int l)
{
	par[i]=p;
	level[i]=l;
	for(auto ch:adj[i])
	{
		if(ch!=p)
			dfs(ch,i,l+1);
	}
}

void BuildTable()
{        
    for(int i=0;i<n;i++)
    {
    	for(int j=0;(1<<j)<n;j++)
    	{
    		LCA[i][j]=-1;
    	}
	}
	
	for(int i=0;i<n;i++)
	{
		LCA[i][0]=par[i];
	}
	
	for(int j=1;(1<<j)<n;j++)
	{
		for(int i=0; i<n;i++)
		{
			if(LCA[i][j-1]!=-1)
			{
				LCA[i][j]=LCA[LCA[i][j-1]][j-1];
			}
		}
	}
}

int get_lca(int p,int q)
{
	int temp;
	if(level[p]<level[q])
	{
		temp=p;
		p=q;
		q=temp;
	}
	int log;
	for(log=1;(1<<log)<=level[p];log++);
	log--;
	
	for(int i=log;i>=0;i--)
	{
		if(level[p]-(1<<i)>=level[q])
		{
			p=LCA[p][i];
		}
	}
	if(p==q)
		return p;
		
	for(int i=log;i>=0;i--)
	{
		if(LCA[p][i]!=-1 && LCA[p][i]!=LCA[q][i])
		{
			p=LCA[p][i];
			q=LCA[q][i];
		}
	}
	return par[p];
}
