#include<bits/stdc++.h>
using namespace std;

const int maxN=1500;

int  n,m;
string arr[maxN];

pair<int,int> distinct[maxN][maxN];

queue<pair<pair<int,int>,pair<int,int> >>q;

void calc(int x,int y,int i,int j)
{
    if(x < 0)
    {
        x = x + n;
        i--;
    }
    if(x >= n)
    {
        x = x - n;
        i++;
    }
    if(y < 0)
    {
        y = y + m;
        j--;
    }
    if(y >= m)
    {
        y = y - m;
        j++;
    }
    if(arr[x][y] == '#')
    {
        return;
    }
    
    if(distinct[x][y] != make_pair((int)1e9,(int)1e9) )
    {
        if(distinct[x][y] != make_pair(i,j))
        {
            cout<<"Yes"<<endl;
            exit(0);
        }
        return;
    }
    distinct[x][y] = {i,j};
    
    q.push({{x,y},{i,j}});
    return ;
}

int main()
{

        cin>>n>>m;
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
                if(arr[i][j] == 'S')
                {
                    x = i;
                    y = j;
                    arr[i][j] = '.';
                }
                distinct[i][j] = {1e9,1e9};
			}
		}
        calc(x,y,0,0);
        
        while(!q.empty())
        {
            int a,b,c,d;
            a = q.front().first.first;
            b = q.front().first.second;
            c = q.front().second.first;
            d = q.front().second.second;
            q.pop();
            calc(a+1,b,c,d);
            calc(a-1,b,c,d);
            calc(a,b+1,c,d);
            calc(a,b-1,c,d);
        }
        cout<<"No\n";
    return 0;
}

