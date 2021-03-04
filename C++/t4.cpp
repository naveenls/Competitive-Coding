#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;
const int k=18;

int arr[maxN];
int suffix[maxN][k]={0};
int sum[maxN][k];
int prefix[maxN][k];

int n;

void BuildTable()
{        
    for(int i=0;i<n;i++)
    {
       	sum[i][0]=arr[i];
       	prefix[i][0]=arr[i];
       	suffix[i][0]=arr[i];
	}
	for(int j=1;j<k;j++)
	{
		for(int i=0; i+(1<<j)<=n;i++)
		{
			sum[i][j]=(sum[i][j-1]+sum[i+(1<<(j-1))][j-1]);
			prefix[i][j]=max(prefix[i][j-1] , sum[i][j-1]+prefix[i+(1<<(j-1))][j-1]);
			suffix[i][j]=max(suffix[i][j-1] + sum[i+(1<<(j-1))][j-1] , suffix[i+(1<<(j-1))][j-1]);
		}
	}
}

int get_pre(int l,int r)
{
	int ssum=0;
	int pre=-1e9;
	for(int j=k-1;j>=0;j--)
	{
		if((1<<j)<=r-l+1)
		{
			
			pre=max(pre,ssum+prefix[l][j]);
			ssum+=sum[l][j];
			l+=(1<<j);
		}
	}
	return pre;
}

int get_suff(int l,int r)
{
	int suff=-1e9;
	for(int j=k-1;j>=0;j--)
	{
		if((1<<j)<=r-l+1)
		{
			
			suff=max(suff+sum[l][j],suffix[l][j]);
			l+=(1<<j);
		}
	}
	return suff;
}
int main()
{
	cin>>n;	
	int pos[61][n];
	int pos1[61][n];
	memset(pos,0,sizeof(pos));
	memset(pos1,0,sizeof(pos1));
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		pos[arr[i]+30][i]=1;
		pos1[arr[i]+30][i]=1;
	}
	
	for(int i=0;i<61;i++)
	{
		if(pos[i][n-1])
		{
			pos[i][n-1]=n-1;
		}
		else
			pos[i][n-1]=n;
			
		for(int j=n-2;j>=0;j--)
		{
			if(pos[i][j])
			{
				pos[i][j]=j;
			}
			else
				pos[i][j]=pos[i][j+1];
		}
	}
	
	for(int i=0;i<61;i++)
	{
		if(pos1[i][0])
		{
			pos1[i][0]=0;
		}
		else
			pos1[i][0]=-1;
			
		for(int j=1;j<n;j++)
		{
			if(pos1[i][j])
			{
				pos1[i][j]=j;
			}
			else
				pos1[i][j]=pos1[i][j-1];
		}
	}
	
	BuildTable();
	int max_val=0;
	for(int i=0;i<n;i++)
	{
		int max_ind=-1;
		int min_ind=n;
		
		int j=arr[i]+30;
		
		for(int k=j+1;k<61;k++)
		{
			if(i<n-1)
				min_ind=min(min_ind,pos[k][i+1]);
			if(i>0)
				max_ind=max(max_ind,pos1[k][i-1]);
		}
		
		int t1=0;
		if(min_ind-1>i+1)
			t1=max(0,get_pre(i+1,min_ind-1));
		
		int t2=0;
		if(max_ind+1<i-1)
			t2=max(0,get_suff(max_ind+1,i-1));
		
		//cout<<min_ind<<' '<<max_ind<<' '<<t1<<' '<<t2<<endl;
		max_val=max(max_val,t1+t2);
	}
	cout<<max_val<<endl;
	return 0;
}
