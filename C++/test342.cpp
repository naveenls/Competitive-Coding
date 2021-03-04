#include<bits/stdc++.h>
using namespace std;

char find_dir(int x1,int y1,int x2,int y2)
{
	if(x1==x2)
	{
		if(y2>y1)
		{
			return 'N';
		}
		else
		{
			return 'S';
		}
	}
	else
	{
		if(x2>x1)
		{
			return 'E';
		}
		else
		{
			return 'W';
		}
	}
}
int main()
{
	int n;
	cin>>n;
	
	int x[n],y[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	char dir[n];
	
	for(int i=0;i<n-1;i++)
	{
		dir[i]=find_dir(x[i],y[i],x[i+1],y[i+1]);
	}
	dir[n]=find_dir(x[n-1],y[n-1],x[0],y[0]);
	
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int j=(i+1)%n;
		
		if(dir[i]=='S' && dir[j]=='E')
			cnt++;
		
		if(dir[i]=='W' && dir[j]=='S')
			cnt++;
		
		if(dir[i]=='N' && dir[j]=='W')
			cnt++;
		
		if(dir[i]=='E' && dir[j]=='N')
			cnt++;
	}
	
	cout<<cnt<<endl;
	return 0;
}
