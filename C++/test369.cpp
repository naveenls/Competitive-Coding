#include<bits/stdc++.h>
using namespace std;

long double DP[10][10];
bool flag[10][10];
int val[10][10];

void find_next(int i,int j,int &x,int &y,int val,bool flag)
{
	x=i,y=j;
	
	if(flag==0)
	{
		y+=val;
		if(y>9)
		{
			y=9-y%10;
			x++;
		}	
	}
	else
	{
		y-=val;
		
		if(y<0)
		{
			y*=-1;
			y--;
			x++;
		}
	}
	//cout<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
}
long double find_expec(int i,int j)
{
	if(i==9 && j==0)
		return 0.0;
		
	if(flag[i][j])
		return DP[i][j];
		
	DP[i][j]=0;
	
	int x,y;
	
	long double cnt=0;
	for(int t=6;t>=1;t--)
	{
		find_next(i,j,x,y,t,i%2);
		if(x>9)
		{
			cnt++;
		}
	}
	if(cnt)
	{
		long double r=0;
		for(int t=6-cnt;t>=1;t--)
		{
			find_next(i,j,x,y,t,i%2);
			
			r+=(1.0+find_expec(x,y));
		}
		//cout<<cnt<<' '<<r<<endl;
		long double p=cnt/6.0;
		
		DP[i][j]+=(r/(6.0*(1-p)));
		DP[i][j]+=(p/(1-p));
	}
	else
	{
		for(int t=6;t>=1;t--)
		{
			find_next(i,j,x,y,t,i%2);
			
			if(val[x][y])
			{
				DP[i][j]+=(1.0/6.0)*(1.0+min(find_expec(x,y),find_expec(x+val[x][y],y)));
			}
			else
			{
				DP[i][j]+=(1.0/6.0)*(1.0+find_expec(x,y));
			}
		}
	}
	flag[i][j]=1;
	return DP[i][j];
}
int main()
{

	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>val[9-i][j];
			flag[i][j]=0;
		}
	}
	
	cout<<fixed<<setprecision(10)<<find_expec(0,0);
	
	//return 0;
}
