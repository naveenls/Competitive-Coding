#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		
		int n=s.size();
		
		vector<int> seg;
		
		int len=0;
		
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				if(len)
				{
					seg.push_back(len);
				}
				len=0;
			}
			else
			{
				len++;
			}
		}
		
		if(len)
		{
			seg.push_back(len);
		}
		
		sort(seg.begin(),seg.end());
		reverse(seg.begin(),seg.end());
		
		int sum1=0;
		bool flag=0;
		
		for(int i=0;i<seg.size();i++)
		{
			if(flag==0)
			{
				sum1+=seg[i];
			}
			flag=1-flag;
		}
		cout<<sum1<<endl;
	}
	return 0;
}
