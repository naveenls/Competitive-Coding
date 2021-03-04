#include <bits/stdc++.h>
using namespace std;

int find_par(int i,int par[])
{
    if(par[i]==i)
        return par[i];
        
    par[i]=find_par(par[i],par);
    return par[i];
}
int main() {

	int n,m;
	cin>>n>>m;
	
    int par[n];
    for(int i=0;i<n;i++)
    {
        par[i]=i;
    }
    
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        u--,v--;
        
        int a=find_par(u,par);
        int b=find_par(v,par);
        
        if(a<b)
        {
        	par[b]=a;
		}
		else
		{
			par[a]=b;
		}
    }
        
    map<int,int> right;
    
    for(int i=0;i<n;i++)
    {
    	right[find_par(i,par)]=i;
	}
	
	vector<pair<int,int> > V;
	for(auto ele:right)
	{
		V.push_back({ele.first,ele.second});
	}
	
	int cnt=0;
	
	for(int i=0;i<V.size();)
	{
		int r=V[i].second;
		
		int j=i+1;
		while(j<V.size() && V[j].first<r)
		{
			r=max(r,V[j].second);
			j++;
		}
		
		cnt+=(j-i-1);
		i=j;	
	}
	cout<<cnt<<endl;
	return 0;
}

