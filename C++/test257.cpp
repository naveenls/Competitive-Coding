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
		
		int m;
		cin>>m;
		
		int b[m];
		for(int i=0;i<m;i++)
			cin>>b[i];
		
		int flag[m]={0};
		
		int start=1;
		while(count(flag,flag+m,0))
		{
			vector<int> curr;
			
			for(int i=0;i<m;i++)
			{
				if(!flag[i])
				{
					int sum=0;
					
					for(int j=0;j<m;j++)
					{
						if(flag[j])
						{
							sum+=abs(i-j);
						}
					}
					if(sum==b[i])
					{
						curr.push_back(i);
					}
				}
			}
			for(auto ele:curr)
				flag[ele]=start;
			start++;
		}
		int cnt[26]={0};
		for(int i=0;i<s.size();i++)
		{
			cnt[s[i]-'a']++;
		}
		int ss=25;
		/*
		for(int i=0;i<m;i++)
		{
			cout<<flag[i]<<' ';
		}
		cout<<endl;*/
		char ans[m];
		for(int i=1;i<start;i++)
		{
			vector<int> positions;
			for(int j=0;j<m;j++)
			{
				if(flag[j]==i)
					positions.push_back(j);
			}
			while(positions.size()>cnt[ss])
			{
				ss--;
			}
			for(auto ele:positions)
				ans[ele]=(char)ss+'a';
			
			ss--;
		}
		
		for(int i=0;i<m;i++)
			cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
