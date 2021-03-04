#include<bits/stdc++.h>
using namespace std;

vector<long long> count_vals(vector<int> slopes)
{
    if(slopes.size()==0)
    {
        return vector<long long>(1,0);
    }
    
    map<int,long long> mp;
    for(auto m:slopes)
    {
        mp[m]++;
    }
    
    vector<long long> count;
    for(auto ele:mp)
    {
        count.push_back(ele.second);
    }
    
    sort(count.begin(),count.end());
    
    vector<long long> sum1(count.size()+1);
    vector<long long> sum2(count.size()+1);
    vector<long long> sum3(count.size()+1);
    
    sum1[count.size()]=0;
    sum2[count.size()]=0;
    sum3[count.size()]=0;
    
    for(int i=count.size()-1;i>=0;i--)
    {
        sum1[i]=count[i]+sum1[i+1];
        sum2[i]=sum2[i+1] + count[i]*sum1[i+1];
        sum3[i]=sum3[i+1] + count[i]*sum2[i+1];
    }
    
    vector<long long> ans;
    
    for(int i=0;i<count.size();i++)
    {
        while(count[i])
        {
            ans.push_back(count[i]*sum2[i+1] + sum3[i+1]);
            count[i]--;
        }
    }
    
    return ans;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,c,k;
		cin>>n>>c>>k;
		
		pair<int,int> line[n];
		int col[n];
		
		long long count[c]={0};
		
		vector<vector<int> > groups(c);
		
		for(int i=0;i<n;i++)
		{
			cin>>line[i].first>>line[i].second;
			cin>>col[i],col[i]--;
			
			groups[col[i]].push_back(line[i].first);
			count[col[i]]++;
		}

		int v[c];
		for(int i=0;i<c;i++)
			cin>>v[i];
		
		vector<vector<long long> > min_triangle(c);
		
		for(int i=0;i<c;i++)
		{
		    min_triangle[i]=count_vals(groups[i]);
		}

		long long DP[c+1][k+1];
		
		for(int j=0;j<=k;j++)
		    DP[c][j]=0;
		    
		for(int i=c-1;i>=0;i--)
		{
		    for(int j=0;j<=k;j++)
		    {
		        DP[i][j]=1e18;
			}
			
			for(int ct=0;ct<=count[i] && ct*v[i]<=k ;ct++)
			{
				long long t=min_triangle[i][ct];
				
				for(int j=ct*v[i];j<=k;j++)
				{
					DP[i][j]=min(DP[i][j],t+DP[i+1][j-ct*v[i]]);
				}
			}
		}

		cout<<DP[0][k]<<endl;
	}
	return 0;
}
