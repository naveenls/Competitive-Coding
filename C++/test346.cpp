#include<bits/stdc++.h>
using namespace std;

const int maxV=101;

long double DP[maxV][maxV][maxV][3];
bool flag[maxV][maxV][maxV];

void find_val(int r,int s,int p)
{
	//cout<<r<<' '<<s<<' '<<p<<endl;
	if(!r && !p)
	{
		DP[r][s][p][0]=0;
		DP[r][s][p][1]=1;
		DP[r][s][p][2]=0;
		return;
	}
	if(!r && !s)
	{
		DP[r][s][p][0]=0;
		DP[r][s][p][1]=0;
		DP[r][s][p][2]=1;
		return;
	}
	if(!s && !p)
	{
		DP[r][s][p][0]=1;
		DP[r][s][p][1]=0;
		DP[r][s][p][2]=0;
		return;
	}
	
	if(flag[r][s][p])
	{
		return;
	}
	
	
	DP[r][s][p][0]=0;
	DP[r][s][p][1]=0;
	DP[r][s][p][2]=0;
	
	long double denom=(r+s+p)*(r+s+p-1)/2;
	
	if(r && s)
	{
		find_val(r,s-1,p);
		
		DP[r][s][p][0]+=(r*s)*DP[r][s-1][p][0]/denom;
		DP[r][s][p][1]+=(r*s)*DP[r][s-1][p][1]/denom;
		DP[r][s][p][2]+=(r*s)*DP[r][s-1][p][2]/denom;
	}
	
	if(r && p)
	{
		find_val(r-1,s,p);
		
		DP[r][s][p][0]+=(r*p)*DP[r-1][s][p][0]/denom;
		DP[r][s][p][1]+=(r*p)*DP[r-1][s][p][1]/denom;
		DP[r][s][p][2]+=(r*p)*DP[r-1][s][p][2]/denom;
	}
	
	if(p && s)
	{
		find_val(r,s,p-1);
		
		DP[r][s][p][0]+=(s*p)*DP[r][s][p-1][0]/denom;
		DP[r][s][p][1]+=(s*p)*DP[r][s][p-1][1]/denom;
		DP[r][s][p][2]+=(s*p)*DP[r][s][p-1][2]/denom;
	}
	
	long double sum=DP[r][s][p][0]+DP[r][s][p][1]+DP[r][s][p][2];
	//cout<<sum<<endl;
	
	flag[r][s][p]=1;	
	DP[r][s][p][0]/=sum;
	DP[r][s][p][1]/=sum;
	DP[r][s][p][2]/=sum;
}

int main()
{
	int r,s,p;
	cin>>r>>s>>p;
	memset(flag,0,sizeof(flag));
	find_val(r,s,p);
	
	cout<<fixed<<setprecision(10)<<DP[r][s][p][0]<<' '<<DP[r][s][p][1]<<' '<<DP[r][s][p][2];
	return 0;
}
