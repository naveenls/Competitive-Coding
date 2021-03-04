#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) c.begin(),c.end()

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int> arr(n);
		rep(i,n)
			cin>>arr[i];
			
		sort(all(arr));
		
		bool flag=0;
		rep(i,n-1)
		{
			if(arr[i]!=arr[i+1] && arr[i+1]!=arr[i]+1)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
