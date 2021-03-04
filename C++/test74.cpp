#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int n;
	cin>>n;
	char arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	vector< pair<int,int> > row;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]=='.')
			{
				row.push_back(i+1,j+1);
				break;
			}
		}
	}
	
	vector< pair<int,int> > column;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j][i]=='.')
			{
				column.push_back(j+1,i+1);
				break;
			}
		}
	}
	if(row.size()==n)
	{
		for(auto ele:row)
		{
			cout<<ele.first<<' '<<ele.second<<endl;
		}
	}
	else if(column.size()==n)
	{
		for(auto ele:column)
		{
			cout<<ele.first<<' '<<ele.second<<endl;
		}
	}
	else
		cout<<-1;
	return 0;
}
