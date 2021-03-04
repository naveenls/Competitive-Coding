#include<bits/stdc++.h>
using namespace std;

const int maxN=110;
const int maxX=1e4+10;

int n,x;

int DP[maxN][maxX];
int arr[maxN];

int find_max(int i,int rem,int arr[])
{
	if(rem<0)
		return -1e9;
		
	if(i==0 && rem>=0)
		return 0;
		
	if(DP[i][rem]!=-1)
		return DP[i][rem];
	
	DP[i][rem]=max(find_max(i-1,rem,arr) , 1+ find_max(i-1,rem-arr[i]*(n-i+1),arr));
	
	return DP[i][rem];
}
int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout);
	cin>>n>>x;
	memset(DP,-1,sizeof(DP));
	
	
	//cout<<n<<endl;
	
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<find_max(n,x,arr)<<endl;
	return 0;
}
