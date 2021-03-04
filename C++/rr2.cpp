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
		
		int arr[2*n];
		
		vector<int> odd,even;
		
		for(int i=0;i<2*n;i++)
		{
			cin>>arr[i];
			if(arr[i]%2)
				odd.push_back(i+1);
			else
				even.push_back(i+1);
		}
		
		if(odd.size()%2)
		{
			odd.pop_back();
		}
		
		for(int i=0;i<n-1;i++)
		{
			if(odd.size()>=2)
			{
				cout<<odd[0]<<' '<<odd[1]<<endl;
				odd.erase(odd.begin());
				odd.erase(odd.begin());
			}
			else
			{
				cout<<even[0]<<' '<<even[1]<<endl;
				even.erase(even.begin());
				even.erase(even.begin());
			}
		}
	}
	return 0;
}
