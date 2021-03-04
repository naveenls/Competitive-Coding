#include<bits/stdc++.h>
using namespace std;

int main(){
    set<pair<int,int> > s;
    set<int> x,y;
    
    int n=4;
    int x1,x2,y1,y2;
    while(n--)
    {
    	cin>>x1>>y1>>x2>>y2;
    	s.insert({x1,y1});
    	s.insert({x2,y2});
    	x.insert(x1);
    	x.insert(x2);
    	y.insert(y1);
    	y.insert(y2);
    	if(x1!=x2 && y1!=y2)
    	{
    		cout<<"NO";
    		return 0;
		}
	}
	if(s.size()==4)
	{
		if(x.size()==2 && y.size()==2)
		{
			bool flag=0;
			for(auto x_:x)
			{
				for(auto y_:y)
				{
					if(s.find({x_,y_})==s.end())
					{
						flag=1;
					}
				}
			}
			if(flag)
			{
				cout<<"NO";
				return 0;
			}
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
	}
	else
	{
		cout<<"NO"<<endl;
	}
    return 0;
}
