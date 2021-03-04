#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	vector<int> pos[n];
	
	multiset<int> ms;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		ms.insert(arr[i]);
		pos[arr[i]].push_back(i);
	}
	
	int last=-1;
	
	vector<int> ans;
	
	for(int i=0;i<n;i++)
	{
		int j=last+1;
		
		while(j>=0 && ms.find(j)==ms.end())
		{
			j-=3;
		}
		if(j<0)
			break;
		
		ans.push_back(j);
		last=j;
		ms.erase(ms.find(j));
	}
	if(ans.size()<n)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		cout<<"Possible"<<endl;
		for(int i=0;i<n;i++)
		{
			//cout<<ans[i]<<endl;
			int ind=pos[ans[i]].size()-1;
			
			cout<<pos[ans[i]][ind]+1<<' ';
			pos[ans[i]].pop_back();
		}
	}

	return 0;
}
