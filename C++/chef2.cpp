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
		int arr[n];
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]==1)
				flag=1;
		}
		if(flag)
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
		
	}
	return 0;
}

