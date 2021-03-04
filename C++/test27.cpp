#include<bits/stdc++.h>
using namespace std;
const int maxN=500;
char arr[maxN][maxN];
bool mark[maxN][maxN];

int n,m,k;

struct Node{
	int i,j;
	int pi,pj;
	int ch=0;
};

Node* ele[maxN][maxN];

void dfs(int i,int j,int pi,int pj)
{
	if(i<n && i>=0 && j<n && j>=0)
	{
		if(!mark[i][j])
		{
			mark[i][j]=true;
			ele[i][j]->i=i;
			ele[i][j]->j=j;
			ele[i][j]->pi=pi;
			ele[i][j]->pj=pj;
			ele[pi][pj]->ch++;
			
			dfs(i-1,j,i,j);
			dfs(i,j-1,i,j);
			dfs(i,j+1,i,j);
			dfs(i+1,j,i,j);
		}
	}
}
int main()
{
	cin>>n>>m>>k;
	memset(mark,0,sizeof(mark));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]=='#')
			{
				mark[i][j]=1;
			}
			ele[i][j]=new Node();
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!mark[i][j])
				dfs(i,j,i,j);
		}
	}
	queue<Node*> q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='.' && ele[i][j]->ch==0)
				q.push(ele[i][j]);
		}
	}
	int cnt=0;
	while(cnt<k)
	{
		Node* temp=q.front();
		q.pop();
		cnt++;
		//cout<<cnt<<endl;
		arr[temp->i][temp->j]='X';
		ele[temp->pi][temp->pj]->ch--;
		if(!ele[temp->pi][temp->pj]->ch)
		{
			q.push(ele[temp->pi][temp->pj]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	return 0;	
}
