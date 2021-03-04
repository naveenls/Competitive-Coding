#include<bits/stdc++.h>
using namespace std;

const int maxN=1000;

int row[maxN]={0};
int col[maxN]={0};
int arr[maxN][maxN]={0};

int n;

void op(int type,int i,int j,int num)
{
	if(type==1)
	{
		int temp=row[i];
		row[i]=row[j];
		row[j]=temp;
		
		for(int k=0;k<num;k++)
		{
			int t=arr[i][k];
			arr[i][k]=arr[j][k];
			arr[j][k]=t;
		}
	}
	else
	{
		int temp=col[i];
		col[i]=col[j];
		col[j]=temp;
		
		for(int k=0;k<num;k++)
		{
			int t=arr[k][i];
			arr[k][i]=arr[k][j];
			arr[k][j]=t;
		}
	}
}

int choose(int type,int num)
{
	if(type==1)
	{
		for(int i=0;i<num;i++)
		{
			if(row[i])
			{
				return i;
			}
		}
	}
	else
	{
		for(int i=0;i<num;i++)
		{
			if(!col[i])
			{
				return i;
			}
		}
	}
	return -1;
}
int main()
{
	cin>>n;
	int u,p;
	
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>p,u--,p--;
		row[u]++;
		col[p]++;
		arr[u][p]=1;
	}
	
	vector<pair<int,int> > v;
	vector<int> type;
	
	int temp=n;
	while(temp>1)
	{
		if(col[temp-1])
		{
			int ind=choose(2,temp);
			if(ind==-1)
				break;
			type.push_back(2);
			v.push_back({ind+1,temp});
			op(2,ind,temp-1,temp);
		}
		if(!row[temp-1])
		{
			int ind=choose(1,temp);
			if(ind==-1)
				break;
			type.push_back(1);
			v.push_back({ind+1,temp});
			op(1,ind,temp-1,temp);
		}
		
		for(int i=0;i<temp;i++)
		{
			col[i]-=arr[temp-1][i];
		}
		temp--;
	}
	cout<<type.size()<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<type[i]<<' '<<v[i].first<<' '<<v[i].second<<endl;
	}
	return 0;
}
