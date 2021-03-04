#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	vector<int> vals;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			vals.push_back(arr[i]);
		}
		else
		{
			sort(vals.begin(),vals.end(),greater<int> ());
			if(vals.size()>=3)
			{
				
			}
			else if(vals.size()==2)
			{
				
			}
			else if(vals.size()==1)
			{
				
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
    return 0;
}
