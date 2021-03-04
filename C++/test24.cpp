#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int i=0,j=1;
	
	set<int> u;
	u.insert(arr[0]);
	int maxN=1e5;
	int count[maxN+1]={0};
	count[arr[0]]++;
	while(j<n)
	{
		if(u.size()<k)
		{
			u.insert(arr[j]);
			count[arr[j]]++;
			j++;
		}
		else
		{
			break;
		}
	}
	while(count[arr[i]]>1 && i<j-1)
	{
		count[arr[i]]--;
		i++;
	}
	if(u.size()==k)
		cout<<i+1<<' '<<j<<endl;
	else
	{
		cout<<-1<<' '<<-1<<endl;
	}
}
