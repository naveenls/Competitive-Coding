#include<bits/stdc++.h>
using namespace std;

int n,m;

int find_par(int i,int par[])
{
	if(i==par[i])
		return i;
		
	par[i]=find_par(par[i],par);
	return par[i];
}

int main()
{
	cin>>n>>m;
	
	int arr[n];
	int par[m];
	int size[m];
	
	for(int i=0;i<m;i++)
	{
		par[i]=i;
	}
	
	vector<int> ind[m];

	int num_inv=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr[i]--;
		
		size[arr[i]]++;
		ind[arr[i]].push_back(i);
	}

	for(int i=0;i<n-1;i++)
	{
		if(arr[i]!=arr[i+1])
		{
			num_inv++;
		}
	}
	
	cout<<num_inv<<endl;
	
	int u,v;
	for(int i=0;i<m-1;i++)
	{
		cin>>u>>v;
		u--,v--;
		
		int a=find_par(u,par);
		int b=find_par(v,par);
		
		if(size[a]<size[b])
		{			
			for(auto ele:ind[a])
			{
				if(ele)
				{
					if(find_par(arr[ele-1],par)==b)
						num_inv--;
				}
				
				if(ele<n-1)
				{
					if(find_par(arr[ele+1],par)==b)
						num_inv--;
				}					
				ind[b].push_back(ele);
			}
			
			size[b]+=size[a];
			par[a]=b;
		}
		else
		{
			int temp;
			
			for(auto ele:ind[b])
			{
				if(ele)
				{
					if(find_par(arr[ele-1],par)==a)
						num_inv--;
				}
				
				if(ele<n-1)
				{
					if(find_par(arr[ele+1],par)==a)
						num_inv--;
				}
				
				ind[a].push_back(ele);
			}
			size[a]+=size[b];
			par[b]=a;
		}
		cout<<num_inv<<endl;
	}
}
