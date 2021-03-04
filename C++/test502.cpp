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
		
		string s;
		cin>>s;
		
		int arr[26]={0};
		
		for(int i=0;i<n;i++)
			arr[s[i]-'a']++;
			
		bool flag=0;
		for(int i=0;i<26;i++)
		{
			if(arr[i]%2)
				flag=1;
		}
		
		if(flag)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
