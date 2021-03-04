#include<bits/stdc++.h>
using namespace std;

int query(string s)
{
	int a;
	cout<<s<<endl;
	cout.flush();
	cin>>a;
	
	return a;
	
}
int main()
{
	int len=query("a");
	
	if(len==0)
		return 0;
			
	len++;
	
	if(len>300)
	{
		string temp(len-1,'b');
		query(temp);
		return 0;
	}
		
	string s(len,'a');
	string ans(len,'a');
	
	int val=query(s);
	
	if(val==len)
	{
		string temp(len-1,'b');
		query(temp);
		return 0;
	}
	
	int num_b=val;
	
	for(int i=0;i<len-1;i++)
	{
		s[i]='b';
		
		int temp=query(s);
		if(temp<val)
		{
			ans[i]='b';
			num_b--;
		}

		s[i]='a';	
	}
	
	if(num_b)
		ans[len-1]='b';
		
	query(ans);
	
	return 0;
}
