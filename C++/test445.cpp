#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

int val[3*maxN+1][3];
int lazy[3*maxN+1];

void merge(int i)
{
	int a1=val[2*i+1][0],a2=val[2*i+1][1],a3=val[2*i+1][2];
	int b1=val[2*i+2][0],b2=val[2*i+2][1],b3=val[2*i+2][2];
	
	val[i][0]=a1+b1;
	val[i][1]=a2+b2;
	val[i][2]=a3+b3;
}

void BuildTree(int arr[],int ind,int start,int end)
{        
        if(start==end)
        {
            val[ind][arr[start]]=1;
        }
        else
        {
            int mid=(start+end)/2;
            BuildTree(arr,2*ind+1,start,mid);
            BuildTree(arr,2*ind+2,mid+1,end);

            merge(ind);
        }
}

void Update(long long diff,int ind,int start,int end,int l,int r)
{
	if(lazy[ind]!=0)
	{
		lazy[ind]%=3;
		
		if(lazy[ind]==1)
		{
			int temp=val[ind][0];
			
			val[ind][0]=val[ind][2];
			val[ind][2]=val[ind][1];
			val[ind][1]=temp;
		}
		else if(lazy[ind]==2)
		{
			int temp=val[ind][0];
			
			val[ind][0]=val[ind][1];
			val[ind][1]=val[ind][2];
			val[ind][2]=temp;
		}
		
		if(start!=end)
		{
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		
		lazy[ind]=0;
	}

	if(r<start || l>end)
		return;

	if(start>=l && end<=r)
	{
		if(diff==1)
		{
			int temp=val[ind][0];
			
			val[ind][0]=val[ind][2];
			val[ind][2]=val[ind][1];
			val[ind][1]=temp;
		}
		else if(diff==2)
		{
			int temp=val[ind][0];
			
			val[ind][0]=val[ind][1];
			val[ind][1]=val[ind][2];
			val[ind][2]=temp;
		}
		
		if(start!=end)
		{
			lazy[2*ind+1]+=diff;
			lazy[2*ind+2]+=diff;
		}
	}
	else
	{
		int mid=(start+end)>>1;
		Update(diff,2*ind+1,start,mid,l,r);
		Update(diff,2*ind+2,mid+1,end,l,r);	
		merge(ind);
	}
}

long long get_sum(int ind,int start,int end,int l,int r)
{
	if(lazy[ind]!=0)
	{
		lazy[ind]%=3;
		
		if(lazy[ind]==1)
		{
			int temp=val[ind][0];
			
			val[ind][0]=val[ind][2];
			val[ind][2]=val[ind][1];
			val[ind][1]=temp;
		}
		else if(lazy[ind]==2)
		{
			int temp=val[ind][0];
			
			val[ind][0]=val[ind][1];
			val[ind][1]=val[ind][2];
			val[ind][2]=temp;
		}

		if(start!=end)
		{
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		
		lazy[ind]=0;
	}

	if(start>r || end<l)
		return 0;

	if(start>=l && end<=r)
	{
		return val[ind][0];
	}
	else
	{
		int mid=(start+end)>>1;
		long long sum1=get_sum(2*ind+1,start,mid,l,r);
		long long sum2=get_sum(2*ind+2,mid+1,end,l,r);	
		return sum1+sum2;
	}
}

int main()
{
	memset(val,0,sizeof(val));
	memset(lazy,0,sizeof(val));
	
	int n,m;
	cin>>n>>m;
	
	string s;
	cin>>s;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		arr[i]=s[i]-'0';
	}
	
	int pref[n];
	
	for(int i=0;i<n;i++)
	{
		pref[i]=arr[i]%3;
		if(i)
			pref[i]=(pref[i]+pref[i-1])%3;	
	}
	
	BuildTree(pref,0,0,n-1);
	int type,x,y;
	
	for(int i=0;i<m;i++)
	{
		cin>>type>>x>>y;
		if(type==1)
		{
			x--;
			Update(((y-arr[x])%3+3)%3,0,0,n-1,x,n-1);
			arr[x]=y;
		}	
		else
		{
			x--,y--;
			cout<<get_sum(0,0,n-1,x,y)<<endl;
		}
	}
	return 0;
}
