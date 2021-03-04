#include<bits/stdc++.h>
using namespace std;

const int maxN=2e5+100;

long long val[3*maxN+1][2][2]={0};

long long mod=1e9+7;
void multiply(int ind)
{
	long long temp[2][2];
	
	int i1=2*ind+2;
	int i2=2*ind+1;
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			temp[i][j]=0;
			
			for(int k=0;k<2;k++)
			{
				temp[i][j]+=val[i1][i][k]*val[i2][k][j];
				temp[i][j]%=mod;
			}
		}
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			val[ind][i][j]=temp[i][j];
	}
}

void BuildTree(string &s,int ind,int start,int end)
{        
        if(start==end)
        {
            if(s[start]=='S' || s[start]=='D')
            {
            	val[ind][0][0]=0;
            	val[ind][0][1]=0;
            	
            	val[ind][1][0]=1;
            	val[ind][1][1]=1;
			}
			else if(s[start]=='H')
			{
				val[ind][0][0]=1;
            	val[ind][0][1]=1;
            	
            	val[ind][1][0]=0;
            	val[ind][1][1]=0;
			}
			else if(s[start]=='A' || s[start]=='E' || s[start]=='I' || s[start]=='O' || s[start]=='U')
			{
				val[ind][0][0]=0;
            	val[ind][0][1]=1;
            	
            	val[ind][1][0]=1;
            	val[ind][1][1]=0;
			}
			else if(s[start]=='?')
			{
				val[ind][0][0]=19;
            	val[ind][0][1]=6;
            	
            	val[ind][1][0]=7;
            	val[ind][1][1]=20;
			}
			else
			{
				val[ind][0][0]=1;
            	val[ind][0][1]=0;
            	
            	val[ind][1][0]=0;
            	val[ind][1][1]=1;
			}
        }
        else
        {
            long long mid=(start+end)/2;
            BuildTree(s,2*ind+1,start,mid);
            BuildTree(s,2*ind+2,mid+1,end);

            multiply(ind);
        }
}

void Update(char c,int pos,int ind,int start,int end)
{
	if(pos<start || pos>end)
		return;

	if(start==end)
	{
		if(c=='S' || c=='D')
        {
        	val[ind][0][0]=0;
        	val[ind][0][1]=0;
        	
        	val[ind][1][0]=1;
        	val[ind][1][1]=1;
		}
		else if(c=='H')
		{
			val[ind][0][0]=1;
        	val[ind][0][1]=1;
        	
        	val[ind][1][0]=0;
        	val[ind][1][1]=0;
		}
		else if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
		{
			val[ind][0][0]=0;
        	val[ind][0][1]=1;
        	
        	val[ind][1][0]=1;
        	val[ind][1][1]=0;
		}
		else if(c=='?')
		{
			val[ind][0][0]=19;
        	val[ind][0][1]=6;
        	
        	val[ind][1][0]=7;
        	val[ind][1][1]=20;
		}
		else
		{
			val[ind][0][0]=1;
        	val[ind][0][1]=0;
        	
        	val[ind][1][0]=0;
        	val[ind][1][1]=1;
		}
	}
	else
	{
		int mid=(start+end)>>1;
		Update(c,pos,2*ind+1,start,mid);
		Update(c,pos,2*ind+2,mid+1,end);	
		multiply(ind);
	}
}

void initialize()
{
	memset(val,0,sizeof(val));
	
	for(int k=0;k<=3*maxN;k++)
	{
		val[k][0][0]=1;
		val[k][1][1]=1;
	}
}

int main()
{
	int n,q;
	cin>>n>>q;
	
	string s;
	cin>>s;
	
	BuildTree(s,0,0,n-1);
	
	cout<<val[0][0][0]<<endl;
	
	int ind;
	char c;
	for(int i=0;i<q;i++)
	{
		cin>>ind>>c,ind--;
		
		Update(c,ind,0,0,n-1);
		cout<<val[0][0][0]<<endl;
	}
	return 0;
}
