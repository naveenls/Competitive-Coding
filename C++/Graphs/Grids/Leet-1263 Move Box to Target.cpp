#define pi pair<int,int>
#define pii pair<pi,pi>
#define x first
#define y second

class Solution {
public:
    
    int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
  
    bool check_near(pi m,pi b)
    {
        if(m.y==b.y)
        {
            if(m.x==b.x-1 || m.x==b.x+1)
            {
                return true;
            }
            return false;
        }
      
        if(m.x==b.x)
        {
            if(m.y==b.y-1 || m.y==b.y+1)
            {
                return true;
            }
            return false;
        }
      
        return false;
    }
  
    int find_dir(pi m,pi b)
    {
        if(m.y==b.y)
        {
            if(m.x==b.x-1)
            {
                return 3;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            if(m.y==b.y-1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }      
    }
    int minPushBox(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
      
        int arr[n][m][n][m];
        
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
              for(int k=0;k<n;k++)
              {
                  for(int l=0;l<m;l++)
                  {
                      arr[i][j][k][l]=1e9;
                  }
              }
          }
        }
        
        pi man,box,target;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='S')
                {
                    man={i,j};
                    grid[i][j]='.';
                }
                if(grid[i][j]=='T')
                {
                    target={i,j};
                    grid[i][j]='.';
                }
                if(grid[i][j]=='B')
                {
                    box={i,j};
                    grid[i][j]='.';
                }
            }
        }
      
        deque<pii> q;
        q.push_front({box,man});
        arr[box.first][box.second][man.first][man.second]=0;
      
        while(!q.empty())
        {
            pii point=q.front();
            q.pop_front();
          
            int b_x=point.x.x;
            int b_y=point.x.y;
          
            int p_x=point.y.x;
            int p_y=point.y.y;
            
            //cout<<b_x<<' '<<b_y<<' '<<p_x<<' '<<p_y<<endl;
            if(check_near(point.x,point.y))
            {
                int d=find_dir(point.y,point.x);
              
                int _x=b_x+dir[d][0];
                int _y=b_y+dir[d][1];
              
                if(_x>=0 && _x<n && _y>=0 && _y<m && grid[_x][_y]=='.')
                {
                    if(arr[_x][_y][b_x][b_y]>arr[b_x][b_y][p_x][p_y]+1)
                    {
                        arr[_x][_y][b_x][b_y]=arr[b_x][b_y][p_x][p_y]+1;
                        q.push_back({{_x,_y},{b_x,b_y}});
                    }
                }
            }
          
            for(int i=0;i<4;i++)
            {
                int _x=p_x+dir[i][0];
                int _y=p_y+dir[i][1];
              
                if(_x==b_x && _y==b_y)
                {
                    continue;
                }
              
                if(_x>=0 && _x<n && _y>=0 && _y<m && grid[_x][_y]=='.')
                {
                    if(arr[b_x][b_y][_x][_y]>arr[b_x][b_y][p_x][p_y])
                    {
                        //cout<<b_x<<' '<<b_y<<' '<<_x<<' '<<_y<<endl;
                      
                        arr[b_x][b_y][_x][_y]=arr[b_x][b_y][p_x][p_y];
                        q.push_front({{b_x,b_y},{_x,_y}});
                    }
                }
            }
            
        }
        
        int mi=1e9;
      
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mi=min(mi,arr[target.x][target.y][i][j]);
            }
        }
        
        if(mi==1e9)
            mi=-1;
      
        return mi;
    }
};
