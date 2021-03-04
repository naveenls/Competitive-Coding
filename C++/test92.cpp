#include<bits/stdc++.h>
using namespace std;

int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<pair<int,int> > v(n);
		
		int a;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			v[i-1]={a,n-i};
		}
		sort(v.begin(),v.end());
		
		int arr[n+1]={0};
		int ma=0;
		for(int i=n-1;i>=0;i--)
		{
			int a=n-v[i].second;
			arr[a]=1;
			
			int j=2*a;
			while(j<=n)
			{
				arr[a]=max(arr[a],arr[j]+1);
			}
			ma=max(ma,arr[a]);
		}
		cout<<ma<<endl;
	}
}
