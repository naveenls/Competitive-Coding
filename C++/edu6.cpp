#include<bits/stdc++.h>
using namespace std;

long long mod=998244353;

const int maxN=5e5;

long long val[3*maxN+1][4]={0};

void merge(int i,long long num)
{
	long long a1=val[2*i+1][0],a2=val[2*i+1][1],a3=val[2*i+1][2],a4=val[2*i+1][3];
	long long b1=val[2*i+2][0],b2=val[2*i+2][1],b3=val[2*i+2][2],b4=val[2*i+2][3];
	
	val[i][0]=(a1*b1%mod+a2*b3*num%mod)%mod;
	val[i][1]=(a1*b2%mod+a2*b4*num%mod)%mod;
	val[i][2]=(a3*b1%mod+a4*b3*num%mod)%mod;
	val[i][3]=(a3*b2%mod+a4*b4*num%mod)%mod;
	
	//cout<<val[i][0]<<' '<<val[i][1]<<' '<<val[i][2]<<' '<<val[i][3]<<endl;
}

void BuildTree(string &s,int ind,int start,int end)
{        
        if(start==end)
        {
            val[ind][0]=s[start]-'0'+1;
            val[ind][1]=1;
            val[ind][2]=1;
            val[ind][3]=0;
        }
        else
        {
            long long mid=(start+end)/2;
            BuildTree(s,2*ind+1,start,mid);
            BuildTree(s,2*ind+2,mid+1,end);
			
			long long value=(s[mid]-'0')*10 + (s[mid+1]-'0');
			value=19-value;
			
			if(value>=10 || value<0)
				value=0;
			
            merge(ind,value);
        }
}

void Update(string &s,int pos,int ind,int start,int end)
{
	if(pos<start || pos>end)
		return;

	if(start==end)
	{
		val[ind][0]=s[pos]-'0'+1;
        val[ind][1]=1;
        val[ind][2]=1;
        val[ind][3]=0;
	}
	else
	{
		int mid=(start+end)>>1;
		Update(s,pos,2*ind+1,start,mid);
		Update(s,pos,2*ind+2,mid+1,end);	
		
		long long value=(s[mid]-'0')*10 + (s[mid+1]-'0');
		value=19-value;
			
		if(value>=10 || value<0)
			value=0;
				
        merge(ind,value);
	}
}
/*
long long find_val(string &s,int n)
{
	long long DP[n+1];
	DP[0]=1;	
	DP[1]=s[0]-'0' +1 ;
	
	for(int i=2;i<=n;i++)
	{
		int temp=find_count(s[i-1]-'0' +(s[i-2]-'0')*10);		
		DP[i]=((s[i-1]-'0'+1)*DP[i-1]%mod + temp*DP[i-2]%mod)%mod;
	}
	return DP[n];
}*/
int main()
{
	int n,m;
	cin>>n>>m;
	
	string s;
	cin>>s;
	
	BuildTree(s,0,0,n-1);
		
	int x;
	char c;
	
	for(int i=0;i<m;i++)
	{
		cin>>x>>c;
		x--;
		s[x]=c;
		
		Update(s,x,0,0,n-1);
		
		cout<<val[0][0]<<endl;
	}
	
	return 0;
}
