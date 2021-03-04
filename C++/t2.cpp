#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int x,y;
		cin>>x>>y;
		string arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int cost=0;
		int M=min(2*x,y);
		for(int i=0;i<n;i++)
		{
			int len=0;
			for(int j=0;j<m;++j)
			{
				if(arr[i][j]=='.')
					len++;
				else
				{
					cost+=(M*(len/2) + x*(len%2));
					len=0;
				}
			}
			cost+=(M*(len/2) + x*(len%2));
		}
		cout<<cost<<endl;
	}
	return 0;
}
