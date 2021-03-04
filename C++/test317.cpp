#include<bits/stdc++.h>
using namespace std;

const int maxN=30000+1;

int val[maxN]={0};

int DP[maxN][500];

int n,d;

int convert(int prev)
{
	int mi=max(0,d-250);
	int ma=min(maxN-1,d+250);
	
	int off_set=prev-mi;
}
int find_max(int i,int p_d)
{
	if(i>=maxN)
		return 0;
		
	int p_d_t=convert(p_d);
	
	if(DP[i][p_d_t])
	{
		return DP[i][p_d_t];
	}
		
	int ans=0;
	ans+=val[i];
	
	if(p_d==2 || p_d==1)
	{
		ans+=find_max(i+1,1);
	}
	else
	{
		int temp=max(find_max(i+p_d-1,p_d-1),find_max(i+p_d,p_d));
		temp=max(temp,find_max(i+p_d+1,p_d+1));
		
		ans+=temp;
	}
	DP[i][p_d_t]=ans;
	
	return ans;
}
int main()
{
	cin>>n>>d;
	
	int p;
	for(int i=0;i<n;i++)
	{
		cin>>p;
		val[p]++;	
	}
	
	memset(DP,-1,sizeof(DP));
	cout<<find_max(d,d)<<endl;
	return 0;
}
