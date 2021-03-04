#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	long long dist[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;++j)
		{
			cin>>dist[i][j];
		}
	}
	
	vector<int> order(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>order[i];
		order[i]--;
	}
	
	reverse(order.begin(),order.end());
	
	vector<long long> sums;
	vector<int> not_deleted;
	for(auto k:order)
	{
		not_deleted.push_back(k);
		
		for (int i = 0; i < n; i++)  
        {   
            for (int j = 0; j < n; j++)  
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        } 
        long long temp=0;
		for (auto i:not_deleted)  
        {   
            for (auto j:not_deleted)  
            {  
            	if(i!=j) 
                	temp+=dist[i][j];
            }  
        }
        
        sums.push_back(temp);
	}
	reverse(sums.begin(),sums.end());
	for(auto ele:sums)
	{
		cout<<ele<<' ';
	}
	
	return 0;
}
