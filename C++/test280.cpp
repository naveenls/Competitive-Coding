#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+1;
const int maxM=10;

int arr[maxM][maxN];
int pos[maxM][maxN];
	
int n,m;

bool check(int val1,int val2)
{
	//cout<<val1<<' '<<val2<<endl;
	for(int j=0;j<m;j++)
	{
		if(pos[j][val2]!=pos[j][val1]+1)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
			pos[i][arr[i][j]]=j;
		}
	
	long long ans=0;
	for(int i=0;i<n;)
	{
		int j=i+1;
		//cout<<j<<"hi"<<endl;
			
		while(j<n && check(arr[0][j-1],arr[0][j]))
		{
			j++;
		}
		
		long long len=j-i;
		//cout<<len<<' '<<j<<endl;
		ans+=len*(len+1)/2;
		i=j;
	}
	cout<<ans<<endl;

	return 0;
}
