#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;

int find_parent(int i,int par[])
{
	if(i==par[i])
		return i;
		
	par[i]=find_parent(par[i],par);
	return par[i];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m,q;
	cin>>n>>m>>q;	
	int par[n];
	int ant[n];
	
	string s;
		
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		ant[i]=-1;
		
		cin>>s;
		mp[s]=i;
	}
	
	int type;
	string u,v;
	
	for(int i=0;i<m;i++)
	{
		cin>>type>>u>>v;
		
		int a=mp[u];
		int b=mp[v];
		
		if(type==1)
		{
			int pa=find_parent(a,par);
			int pb=find_parent(b,par);
			
			if(pa==pb)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				int aa=ant[pa];
				int bb=ant[pb];
				
				if(aa==-1 && bb==-1)
				{
					cout<<"YES"<<endl;
					par[pb]=pa;
				}
				else if(aa!=-1 && bb==-1)
				{
					cout<<"YES"<<endl;
					par[pb]=pa;
				}
				else if(aa==-1 && bb!=-1)
				{
					cout<<"YES"<<endl;
					par[pa]=pb;
				}
				else
				{
					if(aa==pb)
					{
						cout<<"NO"<<endl;
					}
					else
					{
						cout<<"YES"<<endl;
						par[pb]=pa;
						par[bb]=aa;
					}
				}
			}
		}
		else
		{
			int pa=find_parent(a,par);
			int pb=find_parent(b,par);
			
			if(pa==pb)
			{
				cout<<"NO"<<endl;
			}
			else
			{
				int aa=ant[pa];
				int bb=ant[pb];
				
				if(aa==-1 && bb==-1)
				{
					cout<<"YES"<<endl;
					ant[pa]=pb;
					ant[pb]=pa;
				}
				else if(aa!=-1 && bb==-1)
				{
					cout<<"YES"<<endl;
					par[pb]=aa;
				}
				else if(aa==-1 && bb!=-1)
				{
					cout<<"YES"<<endl;
					par[pa]=bb;
				}
				else
				{
					cout<<"YES"<<endl;
					par[pb]=aa;
					par[pa]=bb;
					
					ant[aa]=bb;
					ant[bb]=aa;
				}
			}
		}
	}
	
	for(int i=0;i<q;i++)
	{
		cin>>u>>v;
		
		int a=mp[u];
		int b=mp[v];
		
		int pa=find_parent(a,par);
		int pb=find_parent(b,par);
		
		if(pa==pb)
		{
			cout<<1<<endl;
		}
		else
		{
			if(ant[pa]==pb)
			{
				cout<<2<<endl;
			}
			else
			{
				cout<<3<<endl;
			}
		}
	}
	return 0;
}
