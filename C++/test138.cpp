#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	
	int p=0;
	
	int min_t=0;
	int pos=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='F')
		{
			if(i-pos!=0)
			{
				min_t=max(p+i-pos,min_t);
				p++;
			}
			pos++;
		}
		else
		{
			p--;
			p=max(0,p);
		}
	}
	cout<<min_t<<endl;
	return 0;
}
