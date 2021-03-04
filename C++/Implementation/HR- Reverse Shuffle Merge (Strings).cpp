#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {

    reverse(s.begin(), s.end());

    vector<int> arr[26];
    int cnt[26]={0};
    int needed[26];

    int n=s.size();

    vector<vector<int> > rem(n,vector<int>(26,0));

    for(int i=0;i<s.size();i++)
    {
        cnt[s[i]-'a']++;
        arr[s[i]-'a'].push_back(i);

        rem[i][s[i]-'a']=1;
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<26;j++)
        {
            rem[i][j]+=rem[i+1][j];
        }
    }

    for(int i=0;i<26;i++)
    {
        needed[i]=cnt[i]/2;
    }

    int pos[26]={0};

    string ans="";

    int prev=-1;
    
    for(int i=0;i<s.size()/2;i++)
    {
        char c;
        for(int j=0;j<26;j++)
        {
            if(needed[j])
            {
                int p=arr[j][pos[j]];

                while(p < prev)
                {
                    pos[j]++;
                    p=arr[j][pos[j]];
                }

                bool flag=0;

                for(int k=0;k<26;k++)
                {
                    if(needed[k]>rem[p][k])
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                {
                    prev=p;

                    pos[j]++;
                    needed[j]--;

                    c=j+'a';
                    break;
                }
            }
        }

        ans.push_back(c);
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

