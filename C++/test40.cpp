#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,s;
	cin>>m>>s;
	
	if(s==0)
	{
		if(m==1)
		{
			cout<<0<<' '<<0<<endl;	
		}	
		else
		{
			cout<<-1<<' '<<-1<<endl;
		}
	}
	else
	{
		if(s<=9*m)
		{
			int a[m]={0},b[m]={0};
			a[0]=1;
			b[0]=1;
			s--;
			int i=0;
			int t_new=s;
			while(s)
			{
				int temp=min(s,9-a[i]);
				a[i]+=temp;
				s-=temp;
				i++;
			}
			i=m-1;
			s=t_new;
			while(s)
			{
				int temp=min(s,9-b[i]);
				b[i]+=temp;
				s-=temp;
				i--;
			}
			for(int i=0;i<m;i++)
			{
				cout<<b[i];
			}
			cout<<' ';
			for(int i=0;i<m;i++)
			{
				cout<<a[i];
			}
			cout<<endl;
		}
		else
		{
			cout<<-1<<' '<<-1<<endl;
		}
	}
}
