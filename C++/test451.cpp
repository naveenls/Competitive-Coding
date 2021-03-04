#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,K;
	cin>>n>>K;
	
	int k=0;
	
	vector<vector<int> > v;
	int ma=0;
	
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		temp.push_back(2*k+1);
		temp.push_back(2*k+2);
		temp.push_back(2*k+3);
		temp.push_back(2*k+5);
		
		ma=max(ma,2*k+5);
		k+=3;
		
		v.push_back(temp);
	}
	
	cout<<ma*K<<endl;
	for(auto v1:v)
	{
		for(auto ele:v1)
		{
			cout<<ele*K<<' ';
		}
		cout<<endl;
	}
	return 0;
}
