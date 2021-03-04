#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	int arr[n];
	int pos[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr[i]--;
		
		pos[arr[i]]=i;
	}
	
	set<int> posi,val;
	for(int i=0;i<n;i++)
	{
		val.insert(i);
		posi.insert(i);
	}
	
	int ans[n];
	
	int flag=1;
	while(posi.size())
	{
		int value=*val.rbegin();
		auto itr=posi.find(pos[value]);
		
		vector<int> positions;
		positions.push_back(*itr);
		
		int cnt=0;
		itr++;
		while(cnt<k && itr!=posi.end())
		{
			positions.push_back(*itr);
			cnt++;	
			itr++;
		}
		
		itr=posi.find(pos[value]);
		
		if(itr!=posi.begin())
		{
			itr--;
			cnt=0;
			
			while(cnt<k && itr!=posi.begin())
			{
				positions.push_back(*itr);
				cnt++;	
				itr--;
			}
			if(cnt<k)
			{
				positions.push_back(*itr);
			}	
		}	
		for(auto ele:positions)
		{
			//cout<<ele<<' ';
			ans[ele]=flag;
			posi.erase(ele);
			val.erase(arr[ele]);
		}
		//cout<<endl;
		flag=3-flag;
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
