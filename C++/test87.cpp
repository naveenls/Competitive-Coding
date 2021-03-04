#include<bits/stdc++.h>
using namespace std;

int main()
{
 	int n,m,k;
 	cin>>n>>m>>k;
 	
 	int cnt=(m+2*n-1)/n;
	
	if(k==1)
	{
		vector<int> s;
		s.push_back(1);
		int start=n;
		while(start<m+n+1)
		{
			s.push_back(start);
			start+=n-1;
		}
		cout<<s.size()<<endl;
		for(int i=0;i<s.size();i++)
		{
			cout<<s[i]<<' ';
		}
		return 0;
	}
 	if(cnt*n==m+n)
 	{
 		int ans=cnt*k+1;
 		int arr[ans];
 		for(int i=0;i<cnt*k;i++)
 		{
 			arr[i]=(i/k)*n + 1;
		}
		for(int i=k;i<ans;i+=k)
		{
			arr[i]--;
		}
		arr[ans-1]=m+n;
		cout<<ans<<endl;
		for(int i=0;i<ans;i++)
		{
			cout<<arr[i]<<' ';
		}
	}
	else
	{
		int ans=cnt*k;
 		int arr[ans];
 		for(int i=0;i<cnt*k;i++)
 		{
 			arr[i]=(i/k)*n + 1;
		}
		for(int i=k;i<ans;i+=k)
		{
			arr[i]--;
		}

		cout<<ans<<endl;
		for(int i=0;i<ans;i++)
		{
			cout<<arr[i]<<' ';
		}
	}
    return 0;
}
