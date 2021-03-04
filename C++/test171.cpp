#include<bits/stdc++.h>
using namespace std;

map<string,pair<string,int> > mp;

void decode(string a,string b)
{
	int i=0;
	int cnt1=0;
	
	while(a[i]=='&')
	{
		i++;
		cnt1++;
	}
	
	int j=a.size()-1;
	int cnt2=0;
	
	while(a[j]=='*')
	{
		cnt2++;
		j--;
	}
	
	string inter=a.substr(i,j-i+1);
	
	//cout<<cnt1<<' '<<cnt2<<' '<<inter<<endl;
	if(inter=="void")
	{
		if(cnt1<=cnt2)
		{
			int tt=cnt2-cnt1;
			while(tt--)
			{
				inter.push_back('*');
			}
			mp[b]={inter,cnt2-cnt1};
		}
		else
		{
			mp[b]={"errtype",0};
		}
	}
	else if(inter=="errtype")
		mp[b]={"errtype",0};
	else
	{
		if(mp.find(inter)==mp.end())
		{
			mp[b]={"errtype",0};
			return;
		}
		auto pp=mp[inter];
		
		if(pp.first=="errtype")
		{
			mp[b]={"errtype",0};
		}
		else
		{
			cnt2+=pp.second;
			
			if(cnt1<=cnt2)
			{
				int tt=cnt2-cnt1;
				while(tt--)
				{
					pp.first.push_back('*');
				}
				mp[b]={pp.first,cnt2-cnt1};
			}
			else
			{
				mp[b]={"errtype",0};
			}
		}
		
	}
}

void print(string a)
{
	int i=0;
	int cnt1=0;
	
	while(a[i]=='&')
	{
		i++;
		cnt1++;
	}
	
	int j=a.size()-1;
	int cnt2=0;
	
	while(a[j]=='*')
	{
		cnt2++;
		j--;
	}
	
	string inter=a.substr(i,j-i+1);
	
	//cout<<inter<<' '<<cnt1<<' '<<cnt2<<endl;
	if(inter=="void")
	{
		if(cnt1<=cnt2)
		{
			int tt=cnt2-cnt1;
			while(tt--)
			{
				inter.push_back('*');
			}
			cout<<inter<<endl;
		}
		else
		{
			cout<<"errtype"<<endl;
		}
	}
	else if(inter=="errtype")
		cout<<"errtype"<<endl;
	else
	{
		if(mp.find(inter)==mp.end())
		{
			cout<<"errtype"<<endl;
			return;
		}
		
		auto pp=mp[inter];
		
		if(pp.first=="errtype")
		{
			cout<<"errtype"<<endl;
		}
		else
		{
			cnt2+=pp.second;
			
			string ss="void";
			if(cnt1<=cnt2)
			{
				int tt=cnt2-cnt1;
				while(tt--)
				{
					ss.push_back('*');
				}
				cout<<ss<<endl;
			}
			else
			{
				cout<<"errtype"<<endl;
			}
		}
		
	}
}
int main()
{
	int n;
	cin>>n;
	
	string temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(temp=="typedef")
		{
			string a,b;
			cin>>a>>b;
			decode(a,b);
		}
		else
		{
			string a;
			cin>>a;
			
			print(a);
		}
	}
	return 0;
}
