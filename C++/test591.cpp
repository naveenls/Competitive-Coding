#include<bits/stdc++.h>
using namespace std;

int find_par(int i,int par[])
{
	if(par[i] == i)
		return i;
	
	return par[i] = find_par(par[i],par);
}

int main()
{
	int n;
	cin>>n;
	
	int par1[n*n*n];
	int par2[n*n*n];
	
	bool opened[n*n*n] = {0};
	
	for(int i=0;i<n*n*n;i++)
		par1[i] = i, par2[i] = i;
	
	int m;
	cin>>m;
	
	vector<int> v(m);
	int i,j,k;
	
	for(int t=0;t<m;t++)
	{
		cin>>i>>j>>k;
		i--,j--,k--;
		
		v[t] = i+j*n+k*n*n;
	}
	
	if(m == 0)
	{
		cout<<-1<<endl;
		return 0;		
	}	
	
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	
	vector<vector<int> > adj = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
	int ans = -1;
	
	for(int t=0;t<m;t++)
	{
		int u = v[t];
		int temp = v[t];
		
		i = temp%n;
		temp/=n;
		
		j = temp%n;
		temp/=n;
		
		k = temp;
				
		opened[u] = 1;
		
		for(auto ch:adj)
		{
			int i1=i+ch[0];
			int j1=j+ch[1];
			int k1=k+ch[2];
			
			if(i1>=0 && i1<n && j1>=0 && j1<n && k1>=0 && k1<n)
			{
				int v = i1 + j1*n + k1*n*n;
				
				if(opened[v])
				{					
					int a1 = find_par(u,par1);
					int b1 = find_par(v,par1);
					
					int a2 = find_par(u,par2);
					int b2 = find_par(v,par2);
					
					if(a1%n < b1%n){
						par1[b1] = a1;
					}
					else
					{
						par1[a1] = b1;
					}
					
					if(a2%n > b2%n)
					{
						par2[b2] = a2;
					}
					else
					{
						par2[a2] = b2;
					}
				}
			}
		}
		
		int p1 = find_par(u,par1);
		int p2 = find_par(u,par2);
		
		if(((p1%n) == 0) && ((p2%n) == n-1))
		{
			ans = t+1;
			break;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
