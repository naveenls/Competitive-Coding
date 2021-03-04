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
	string ans[n];
	vector<pair<int,int> > vals;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			vals.push_back({arr[i],i});
		}
		else
		{
			sort(vals.begin(),vals.end());
			if(vals.size()>=3)
			{
				int num=vals.size();
				int a1=vals[num-1].second;
				int a2=vals[num-2].second;
				int a3=vals[num-3].second;
				ans[a1]="pushBack";
				ans[a2]="pushQueue";
				ans[a3]="pushStack";
				
				for(int j=0;j<num-3;j++)
				{
					ans[vals[j].second]="pushFront";
				}
				ans[i]="3 popStack popQueue popBack";
			}
			else if(vals.size()==2)
			{
				ans[vals[0].second]="pushStack";
				ans[vals[1].second]="pushQueue";
				ans[i]="2 popStack popQueue";
			}
			else if(vals.size()==1)
			{
				ans[vals[0].second]="pushStack";
				ans[i]="1 popStack";
			}
			else
			{
				ans[i]="0";
			}
			vals.clear();
		}
	}
	for(int i=0;i<vals.size();i++)
	{
		ans[vals[i].second]="pushStack";
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<endl;
	}
    return 0;
}
