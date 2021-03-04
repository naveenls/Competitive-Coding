#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		
		string arr[r];
		
		int mi=5;
		
		int row[r]={0};
		int col[c]={0};
		
		int cnt=0;
		
		for(int i=0;i<r;i++)
		{
			cin>>arr[i];
			for(int j=0;j<c;j++)
			{
				if(arr[i][j]=='A')
				{
					mi=4;
					cnt++;
					
					row[i]++;
					col[j]++;
				}
			}
		}
		
		if(col[0] || col[c-1] || row[0] || row[r-1])
		{
			mi=3;
		}
		if(arr[0][0]=='A' || arr[0][c-1]=='A' || arr[r-1][0]=='A' || arr[r-1][c-1]=='A')
		{
			mi=2;
		}
		for(int i=1;i<r-1;i++)
		{
			if(row[i]==c)
			{
				mi=2;
				break;
			}
		}
		for(int i=1;i<c-1;i++)
		{
			if(col[i]==r)
			{
				mi=2;
				break;
			}
		}
		if(col[0]==r || col[c-1]==r || row[0]==c || row[r-1]==c)
		{
			mi=1;
		}
		if(cnt==r*c)
			mi=0;
			
		if(mi==5)
		{
			cout<<"MORTAL"<<endl;
		}
		else
		{
			cout<<mi<<endl;
		}
	}
	return 0;
}
