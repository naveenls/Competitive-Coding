#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int n;

int countPair(char str[][1000], int n)
{
    int cnt[32] = { 0 };

    for (int i = 0; i < n; i++) {

        int mask = 0;
        for (int j = 0; str[i][j] != '\0'; ++j)
        {
            switch(str[i][j])
            {
            case 'a':
                str[i][j]='0';
                break;
            case 'e':
                str[i][j]='1';
                break;
            case 'i':
                str[i][j]='2';
                break;
            case 'o':
                str[i][j]='3';
                break;
            case 'u':
                str[i][j]='4';
                break;
            }
            mask |= (1 << (str[i][j] - '0'));
        }
        cnt[mask]++;
    }

    int ans = 0;
    for (int m1 = 0; m1 <= 31; m1++)
        for (int m2 = 0; m2 <= 31; m2++)
            if ((m1 | m2) == 31) {

                ans += ((m1 == m2) ?
                       (cnt[m1] * (cnt[m1] - 1)) :
                       (cnt[m1] * cnt[m2]));
            }

    return ans/2;
}

int main()
{
int T;
cin>>T;
while(T--)
{

    cin>>n;
    char D[n][1000];
    for(int i=0;i<n;i++)
    {
        cin>>D[i];
    }
    cout << countPair(D, n) << endl;
}
return 0;
}
