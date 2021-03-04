#include<bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
int main()
{
	int n;
	cin>>n;
	
	int arr[n+1];
	
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	stack<int> s;
	
	int life[n+1];
	life[0]=INF;
	s.push(0);
	arr[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		life[i]=1;
		while(!s.empty() && arr[s.top()]<arr[i])
		{
			life[i]=max(life[i], life[s.top()] + 1);
			s.pop();
		}
		s.push(i);
	}
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		if(life[i]<INF)
			ma=max(ma,life[i]);
	}
	cout<<ma<<endl;
	return 0;
}
