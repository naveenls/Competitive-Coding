#include<bits/stdc++.h>
using namespace std;

set< pair<int,int> > s;
void find_neighbours(int x,int y,vector<int> &v)
{
	if(s.find({x+1,y})!=s.end())
	{
		v.push_back({x+1,y});
	}
	if(s.find({x,y+1})!=s.end())
	{
		v.push_back({x,y+1});
	}
	if(s.find({x-1,y})!=s.end())
	{
		v.push_back({x-1,y});
	}
	if(s.find({x,y-1})!=s.end())
	{
		v.push_back({x,y-1});
	}
	if(s.find({x+1,y+1})!=s.end())
	{
		v.push_back({x+1,y+1});
	}
	if(s.find({x-1,y-1})!=s.end())
	{
		v.push_back({x-1,y-1});
	}
	if(s.find({x+1,y-1})!=s.end())
	{
		v.push_back({x+1,y-1});
	}
	if(s.find({x-1,y+1})!=s.end())
	{
		v.push_back({x-1,y+1});
	}
}
int main()
{
	int x,y,x1,y1;
	cin>>x>>y>>x2>>y1;
	
	int n;
	cin>>n;
	int row,l,r;
	
	for(int i=0;i<n;i++)
	{
		cin>>row>>l>>r;
		for(int j=l;j<=r;j++)
		{
			s.insert(row,j);
		}
	}
	queue<pair<int,int> > q;
	queue<int> dist;
	q.push({x,y});
	dist.push(0);
	
	s.erase({x,y});
	while(!q.empty())
	{
		auto point=q.front();
		q.pop();
		int temp=dist.pop();
		if(point.first==x1 && point.second==x2)
		{
			cout<<temp<<endl;
			return 0;
		}
		vector<pair<int,int> > v;
		find_neighbours(point.first,point.second);
		for(auto ele:v)
		{
			q.push({ele.first,ele.second});
			dist.push(temp+1);
			s.erase({ele.first,ele.second});
		}
	}
	cout<<-1<<endl;
	return 0;
}
