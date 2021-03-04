#include<bits/stdc++.h>
using namespace std;

const int maxN=250;

int arr[maxN][maxN];
int val[maxN][maxN];

int r,c;

bool check(int k)
{
    int corners[4][2];
    memset(corners,-1,sizeof(corners));
    
    for(int x=0;x<r;x++)
    {
        for(int y=0;y<c;y++)
        {
            if(val[x][y]>k)
            {
                if(corners[0][0]==-1)
                {
                    corners[0][0]=x;
                    corners[0][1]=y;
                    
                    corners[1][0]=x;
                    corners[1][1]=y;
                    
                    corners[2][0]=x;
                    corners[2][1]=y;
                    
                    corners[3][0]=x;
                    corners[3][1]=y;
                }
                else
                {
                    if(x+y<corners[0][0]+corners[0][1])
                    {
                        corners[0][0]=x;
                        corners[0][1]=y;
                    }
                    if(-x+y < -corners[1][0]+corners[1][1])
                    {
                        corners[1][0]=x;
                        corners[1][1]=y;
                    }
                    if(x - y < corners[2][0]-corners[2][1])
                    {
                        corners[2][0]=x;
                        corners[2][1]=y;
                    }
                    if(-x - y < -corners[3][0]-corners[3][1])
                    {
                        corners[3][0]=x;
                        corners[3][1]=y;
                    }
                }
            }
        }
    }
    
    if(corners[0][0]==-1)
        return true;
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int cnt=0;
            if(abs(i-corners[0][0])+abs(j-corners[0][1]) <=k )
            {
                cnt++;
            }
            if(abs(i-corners[1][0])+abs(j-corners[1][1]) <=k )
            {
                cnt++;
            }
            if(abs(i-corners[2][0])+abs(j-corners[2][1]) <=k )
            {
                cnt++;
            }
            if(abs(i-corners[3][0])+abs(j-corners[3][1]) <=k )
            {
                cnt++;
            }
            
            if(cnt==4)
                return true;
        }
    }
    
    return false;
}

void initialize()
{
	memset(val,-1,sizeof(val));
	
	queue<pair<int,int> > q;
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(arr[i][j])
			{
				val[i][j]=0;
				q.push({i,j});
			}
		}
	}
	
	while(!q.empty())
	{
		auto pr=q.front();
		q.pop();
		
		int x=pr.first;
		int y=pr.second;
		
		if(x+1<r && val[x+1][y]==-1)
		{
			val[x+1][y]=val[x][y]+1;
			q.push({x+1,y});
		}
		if(x && val[x-1][y]==-1)
		{
			val[x-1][y]=val[x][y]+1;
			q.push({x-1,y});
		}
		if(y+1<c && val[x][y+1]==-1)
		{
			val[x][y+1]=val[x][y]+1;
			q.push({x,y+1});
		}
		if(y && val[x][y-1]==-1)
		{
			val[x][y-1]=val[x][y]+1;
			q.push({x,y-1});
		}
	}
}

void solve()
{
    cin>>r>>c;

    string s;
    
	for(int i=0;i<r;i++)
	{
	    cin>>s;
	    
		for(int j=0;j<c;j++)
			arr[i][j]=s[j]-'0';	
	}

    initialize();
    
	int lo=0,hi=r*c;
	int ans;
	
	while(lo<=hi)
	{
	    int mid=(lo+hi)/2;
	    
	    if(check(mid))
	    {
	        hi=mid-1;
	        ans=mid;
	    }
	    else
	    {
	        lo=mid+1;
	    }
	}
	
	cout<<ans<<endl;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve(); 
	}
	return 0;
}
