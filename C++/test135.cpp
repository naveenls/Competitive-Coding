#include<bits/stdc++.h>
using namespace std;
int count_val(int a[])
{
	int c=0;
	for(int i=0;i<4;i++)
		c+=a[i];
		
	c=4-c;
	
	return c;
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	bool rows[n+1]={0};
	bool cols[n+1]={0};
	
	rows[1]=1;
	rows[n]=1;
	cols[1]=1;
	cols[n]=1;
	
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		rows[a]=1;
		cols[b]=1;
	}
	int cnt=0;
	for(int i=2;i<=n/2 ;i++ )
	{
		int arr[4]={0};
		arr[0]=rows[i];
		arr[1]=rows[n-i+1];
		arr[2]=cols[i];
		arr[3]=cols[n-i+1];
		cnt+=count_val(arr);
	}
	if(n%2)
	{
		if(rows[(n+1)/2]==0 || cols[(n+1)/2]==0)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
