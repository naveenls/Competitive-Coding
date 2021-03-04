#include<bits/stdc++.h>
using namespace std;

int find_max(int a,int b,int c)
{
	if(a<0 || b<0 || c<0)
		return -1e9;
		
	int num_weeks=min(a/3,b/2);
	num_weeks=min(num_weeks,c/2);
	
	a-=num_weeks*3;
	b-=num_weeks*2;
	c-=num_weeks*2;
	
	int num_days=num_weeks*7;
	if(a)
	{
		a--;
		num_days++;
	}
	else
	{
		return num_days;
	}
	if(b)
	{
		b--;
		num_days++;
	}
	else
	{
		return num_days;
	}
	if(c)
	{
		c--;
		num_days++;
	}
	else
	{
		return num_days;
	}
	if(a)
	{
		a--;
		num_days++;
	}
	else
	{
		return num_days;
	}
	if(c)
	{
		c--;
		num_days++;
	}
	else
	{
		return num_days;
	}
	if(b)
	{
		b--;
		num_days++;
	}
	else
	{
		return num_days;
	}
	if(a)
	{
		a--;
		num_days++;
	}
	else
	{
		return num_days;
	}
	
	return num_days;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	
	int arr[3];
	int a_[7]={0,1,2,0,2,1,0};
	
	int ma=0;
	
	for(int len=1;len<=6;len++)
	{
		for(int i=0;i<=7-len;i++)
		{
			int j=i+len-1;
			int cnta=0,cntb=0,cntc=0;
			
			for(int k=i;k<=j;k++)
			{
				if(a_[k]==0)
					cnta++;
				if(a_[k]==1)
					cntb++;
				if(a_[k]==2)
					cntc++;
			}
			if(cnta<=a && cntb<=b && cntc<=c)
			{
				ma=max(ma,len);
			}
		}
	}
	
	ma=max(ma,find_max(a,b,c));
	ma=max(ma,1+find_max(a-1,b,c));
	ma=max(ma,2+find_max(a-1,b-1,c));
	ma=max(ma,3+find_max(a-1,b-1,c-1));
	ma=max(ma,4+find_max(a-2,b-1,c-1));
	ma=max(ma,5+find_max(a-2,b-1,c-2));
	ma=max(ma,6+find_max(a-2,b-2,c-2));
	cout<<ma<<endl;
	return 0;
}
