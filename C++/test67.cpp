#include<bits/stdc++.h>
using namespace std;

struct point{
	int x,y;
	int px,py;
	point(int a,int b, int pa,int pb)
	{
		x=a;
		y=b;
		px=pa;
		py=pb;
	}
	void rotate()
	{
		int tempx=x-px;
		int tempy=y-py;
		x=-tempy;
		y=tempx;
		x+=px;
		y+=py;
	}
};
int distSq(point p, point q) 
{ 
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y); 
} 
  
// This function returns true if (p1, p2, p3, p4) form a 
// square, otherwise false 
bool isSquare(point p1, point p2, point p3, point p4) 
{ 
    int d2 = distSq(p1, p2); // from p1 to p2 
    int d3 = distSq(p1, p3); // from p1 to p3 
    int d4 = distSq(p1, p4); // from p1 to p4 
  
    if (d2 == 0 || d3 == 0 || d4 == 0)     
        return false; 
  
    // If lengths if (p1, p2) and (p1, p3) are same, then 
    // following conditions must met to form a square. 
    // 1) Square of length of (p1, p4) is same as twice 
    // the square of (p1, p2) 
    // 2) Square of length of (p2, p3) is same 
    // as twice the square of (p2, p4) 
  
    if (d2 == d3 && 2 * d2 == d4 
        && 2 * distSq(p2, p4) == distSq(p2, p3)) { 
        return true; 
    } 
  
    // The below two cases are similar to above case 
    if (d3 == d4 && 2 * d3 == d2 
        && 2 * distSq(p3, p2) == distSq(p3, p4)) { 
        return true; 
    } 
    if (d2 == d4 && 2 * d2 == d3 
        && 2 * distSq(p2, p3) == distSq(p2, p4)) { 
        return true; 
    } 
  
    return false; 
} 
int calculate(point p1,point p2,point p3,point p4)
{
	int min_moves=1000;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				for(int l=0;l<4;l++)
				{
					if(isSquare(p1,p2,p3,p4))
					{
						min_moves=min(i+j+k+l,min_moves);
					}	
					p4.rotate();		
				}
				p3.rotate();
			}
			p2.rotate();
		}
		p1.rotate();
	}
	if(min_moves==1000)
		return -1;
	return min_moves;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x,y,a,b;
		cin >>x>>y>>a>>b;
		point p1=point(x,y,a,b);
		cin >>x>>y>>a>>b;
		point p2=point(x,y,a,b);
		cin >>x>>y>>a>>b;
		point p3=point(x,y,a,b);
		cin >>x>>y>>a>>b;
		point p4=point(x,y,a,b);
		cout<<calculate(p1,p2,p3,p4)<<endl;
	}
}
