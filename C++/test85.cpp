#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6+1;

int main()
{
    string s;
    cin>>s;
    string final;
    cin>>final;
    
    vector<int> arr[26];
    for(int i=0;i<s.size();i++)
    {
    	arr[s[i]-'a'].push_back(i);
	}
	
	int l=1,r=final.size();
	int ans=-1;
	bool flag=0;
	
	while(l<=r)
	{
		int mid=(l+r)/2;
		
		int cnt=1;
		int ind=-1;
		bool f=0;
		
		for(int i=0;i<final.size();i++)
		{
			int temp=final[i]-'a';
			
			if(arr[temp].size()==0)
			{
				f=1;
				break;
			}
			
			auto temp1=upper_bound(arr[temp].begin(),arr[temp].end(),ind);
			
			if(temp1==arr[temp].end())
			{
				cnt++;
				ind=arr[temp][0];
			}
			else
			{
				ind=*temp1;
			}
		}
		if(f)
		{
			flag=f;
			break;
		}
		if(cnt>mid)
		{
			l=mid+1;
		}
		else
		{
			ans=mid;
			r=mid-1;
		}
	}
	if(flag)
	{
		cout<<-1;
		return 0;
	}
	cout<<cnt<<endl;
    return 0;
}
