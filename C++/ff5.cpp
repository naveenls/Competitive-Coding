#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		vector<int> arr[k];
		
		for(int i=0;i<k;i++)
		{
			int c;
			cin>>c;
			
			int temp;
			for(int j=0;j<c;j++)
			{
				cin>>temp;
				arr[i].push_back(temp);
			}
		}
		
		cout<<'?'<<' '<<n<<' ';
		for(int i=1;i<=n;i++)
		{
			cout<<i<<' ';
		}
		cout<<endl;
		cout.flush();
		
		int max;
		cin>>max;
		
		int i=0,j=k-1;
		
		while(i<j)
		{
			int mid=(i+j)/2;
			
			vector<int> temp;
			
			for(int p=i;p<=mid;p++)
			{
				for(auto ele:arr[p])
				{
					temp.push_back(ele);
				}
			}
			cout<<'?'<<' '<<temp.size()<<' ';
			
			for(auto ele:temp)
			{
				cout<<ele<<' ';
			}
			cout<<endl;
			cout.flush();
			
			int m_temp;
			
			cin>>m_temp;
			
			if(m_temp==max)
			{
				j=mid;
			}
			else
			{
				i=mid+1;
			}
		}
		vector<int> temp;
		
		set<int> s;
		
		for(auto ele:arr[i])
			s.insert(ele);
		
		for(int p=1;p<=n;p++)
		{
			if(s.find(p)==s.end())
			{
				temp.push_back(p);
			}
		}
		cout<<'?'<<' '<<temp.size()<<' ';
			
		for(auto ele:temp)
		{
			cout<<ele<<' ';
		}
		cout<<endl;
		cout.flush();
		
		int s_temp;
		cin>>s_temp;
		
		cout<<'!'<<' ';
		for(int p=0;p<k;p++)
		{
			if(p==i)
				cout<<s_temp<<' ';
			else
				cout<<max<<' ';	
		}
		cout<<endl;
		cout.flush();
		
		string out;
		cin>>out;
		if(out=="Incorrect")
			return 0;
	}
	return 0;
}
