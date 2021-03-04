#include<bits/stdc++.h>
using namespace std;
 
long long find_sum(vector<long long> &v,int len,int i)
{
	long long ma=-1e18;
	long long sum=0;
	
	while(len--)
	{
		sum+=v[i];
		i=(i+1)%v.size();
		
		ma=max(ma,sum);
	}
	
	return ma;
}

long long find_max(vector<long long> &v,long long k)
{	
	int len=min(k,(long long)v.size());

	long long sum=0;
	
	for(int i=0;i<v.size();i++)
	{
		sum+=v[i];
	}
	
	long long ma=-1e18;
	
	for(int i=0;i<v.size();i++)
	{
		ma=max(ma,find_sum(v,len,i));
		
		long long num_rot=k/v.size();
		int rem=k%v.size();
				
		ma=max(ma,find_sum(v,rem,i) + num_rot*sum);
	}
	
	return ma;
}

int main()
{
  	int n,k;
  	cin>>n>>k;
  	
  	int p[n];
  	for(int i=0;i<n;i++)
  	{
  		cin>>p[i];
  		p[i]--;
	}
	
	long long c[n];
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	
	bool col[n]={0};
	
	vector<vector<long long> > cycles;
	
	for(int i=0;i<n;i++)
	{
		if(col[i]==0)
		{
			col[i]=1;
			
			vector<long long> temp={c[i]};
			
			int start=p[i];
			while(!col[start])
			{				
				temp.push_back(c[start]);
				
				col[start]=1;
				start=p[start];
			}
			
			cycles.push_back(temp);
		}
	}
	
	long long ma=-1e18;
	for(int i=0;i<cycles.size();i++)
	{
		ma=max(ma,find_max(cycles[i],k));
	}
	
	cout<<ma<<endl;
  	return 0;
}
