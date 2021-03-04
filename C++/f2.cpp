#include<bits/stdc++.h>
using namespace std;

string findSubString(string str) 
{ 
    int n = str.length(); 
 
    int dist_count = 3;

    int start = 0, start_index = -1, min_len = INT_MAX; 
  
    int count = 0; 
    int curr_count[3] = { 0 }; 
    for (int j = 0; j < n; j++) { 
        curr_count[str[j]-'1']++; 
  
        if (curr_count[str[j]-'1'] == 1) 
            count++; 
  
        if (count == dist_count) { 
     
            while (curr_count[str[start]-'1'] > 1) { 
                if (curr_count[str[start]-'1'] > 1) 
                    curr_count[str[start]-'1']--; 
                start++; 
            } 
  
            int len_window = j - start + 1; 
            if (min_len > len_window) { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
     if(start_index==-1)
     	return "";

    return str.substr(start_index, min_len); 
} 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		string ans=findSubString(s);
		cout<<ans.size()<<endl;
	}
	return 0;
}
