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
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		vector<int> len;
		
		bool flag=0;
		int s=-1;
		
		for(int i=0;i<n;i++)
		{
			if(flag==0)
			{
				if(arr[i]==0)
				{
					s=i;
					flag=1;	
				}	
			}
			else
			{
				if(arr[i]==1)
				{
					len.push_back(i-s);
					flag=0;	
				}	
			}	
		}
		
		sort(len.begin(),len.end(),greater<int> ());
		
		if(len.size()==0)
		{
			cout<<"No"<<endl;
		}
		else if(len.size()==1)
		{
			if(len[0]%2)
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
		else
		{
			if(len[0]%2)
			{
				int val=len[0]-len[0]/2;
				int nect_val=len[1];
				
				if(nect_val>=val)
				{
					cout<<"No"<<endl;
				}
				else
				{
					cout<<"Yes"<<endl;
				}
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
	}
	
	return 0;
}
