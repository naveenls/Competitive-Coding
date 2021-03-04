#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long long,long long> p1,pair<long long,long long> p2)
{
	return p1.first*p1.first + p1.second*p1.second< p2.first*p2.first + p2.second*p2.second;
}
int main()
{
	long long n;
	cin>>n;
	vector<pair<long long,long long> > v(n);
	long long x,y;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		v[i]=make_pair(x,y);
		if(x)
			sum++;
		if(y)
			sum++;
	}	
	sort(v.begin(),v.end(),compare);
	//cout<<"hi\nhello";
	string s="";
	cout<<2*sum+2*n<<endl;
	for(int i=0;i<n;i++)
	{
		x=v[i].first;
		y=v[i].second;
		if(x>0)
		{
			s+="1 "+to_string(x)+" R\n";
			//cout<<1<<' '<<x<<' '<<'R'<<endl;
		}
		else if(x<0)
		{
			s+="1 "+to_string(-x)+" L\n";
			//cout<<1<<' '<<-x<<' '<<'L'<<endl;
		}
	
		if(y>0)
		{
			s+="1 "+to_string(y)+" U\n";
			//cout<<1<<' '<<y<<' '<<'U'<<endl;
		}
		else if(y<0)
		{
			s+="1 "+to_string(-y)+" D\n";
			//cout<<1<<' '<<-y<<' '<<'D'<<endl;
		}
		s+="2\n";
		//cout<<2<<endl;
		
		if(y>0)
		{
			s+="1 "+to_string(y)+" D\n";
			//cout<<1<<' '<<y<<' '<<'U'<<endl;
		}
		else if(y<0)
		{
			s+="1 "+to_string(-y)+" U\n";
			//cout<<1<<' '<<-y<<' '<<'D'<<endl;
		}
		
		if(x>0)
		{
			s+="1 "+to_string(x)+" L\n";
			//cout<<1<<' '<<x<<' '<<'R'<<endl;
		}
		else if(x<0)
		{
			s+="1 "+to_string(-x)+" R\n";
			//cout<<1<<' '<<-x<<' '<<'L'<<endl;
		}
		s+="3\n";
	}
		//cout<<3<<endl;
	cout<<s;
	return 0;
}
