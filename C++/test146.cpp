#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+1;

int main()
{
	int n;
	cin>>n;
	int arr[maxN];
	
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr[a]=1;
	}
	
	vector<pair<int,int> > un_marked;
	vector<int> ans(n);
	
	int needed=0;
	
	int ind=0;
	for(int i=1;i<maxN;i++)
	{
		if(arr[i]==1)
		{
			if(!arr[maxN-i])
			{
				ans[ind]=maxN-i;
				ind++;
			}
			else
			{
				needed++;
				arr[maxN-i]=2;
			}
		}
	}
	
	for(int i=1;i<maxN && needed ;i++)
	{
		if(arr[i]==0 && arr[maxN-i]==0)
		{
			ans[ind]=i;
			ans[ind+1]=maxN-i;
			ind+=2;
			needed--;
		}
	}
	cout<<n<<endl;
	for(auto ele:ans)
	{
		cout<<ele<<' ';
	}
}
