#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+10;

map <int, vector <pair <int, int>>> mp;
vector <pair <int, int>> shoes;

long long DP[maxN][4];

long long find_max(int ind, int mask)
{
    if(DP[ind][mask]!=-1)
    {
        return DP[ind][mask];
    }
    if(ind==shoes.size())
    {
        return 0;
    }

    auto itr = mp.find(shoes[ind].first);
    long long answer = find_max(ind+1, 0);
	
    if(itr!=mp.end())
    {
        bool mode = false;
        if(ind!=shoes.size()-1 && shoes[ind].first+1==shoes[ind+1].first)
        {
            mode = true;
        }

        for(int i = 0;i<itr->second.size();i++)
        {
            if(itr->second[i].first < shoes[ind].second) continue;
			
			long long temp = shoes[ind].second + find_max(ind+1, (1<<i)*mode);
			if(temp>answer)
			{
				answer=temp;
			}
        }
    }

    itr = mp.find(shoes[ind].first-1);
    if(itr!=mp.end())
    {
        for(int i = 0;i<itr->second.size();i++)
        {
            if(((mask>>i)&1)==1) continue;
            if(itr->second[i].first < shoes[ind].second) continue;

            long long temp=shoes[ind].second + find_max(ind+1, 0);
            if(temp>answer)
			{
				answer=temp;
			}
        }
    }

    DP[ind][mask] = answer;
    return answer;
}

long long value;
vector <pair <int, int>> answer;
map <pair <int, int>, int> shoe2Index;

void recover(int ind, int mask)
{
    if(ind==shoes.size())
    {
        return;
    }

    auto it = mp.find(shoes[ind].first);
    if(0 + find_max(ind+1, 0) == value)
    {
        value -= 0;
        recover(ind+1, 0);

        return;
    }

    if(it!=mp.end())
    {
        bool mode = false;
        if(ind!=shoes.size()-1 && shoes[ind].first+1==shoes[ind+1].first)
        {
            mode = true;
        }

        for(int i = 0;i<it->second.size();i++)
        {
            if(it->second[i].first < shoes[ind].second) continue;
            if(shoes[ind].second + find_max(ind+1, (1<<i)*mode) == value)
            {
                answer.push_back({it->second[i].second, shoe2Index[ shoes[ind] ]});

                value -= shoes[ind].second;
                recover(ind+1, (1<<i)*mode);

                return;
            }
        }
    }

    it = mp.find(shoes[ind].first-1);
    if(it!=mp.end())
    {
        for(int i = 0;i<it->second.size();i++)
        {
            if(((mask>>i)&1)==1) continue;
            if(it->second[i].first < shoes[ind].second) continue;

            if(shoes[ind].second + find_max(ind+1, 0) == value)
            {
                answer.push_back({it->second[i].second, shoe2Index[ shoes[ind] ]});

                value -= shoes[ind].second;
                recover(ind+1, 0);

                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0;i<n;i++)
    {
        int c, s;
        cin >> c >> s;

        shoes.push_back({s, c});
        shoe2Index[{s, c}] = i;
    }
    sort(shoes.begin(), shoes.end());

    int m;
    cin >> m;
    for(int i = 0;i<m;i++)
    {
        int d, l;
        cin >> d >> l;

        mp[l].push_back({d, i});
    }

    for(auto it = mp.begin();it!=mp.end();it++)
    {
        sort(it->second.begin(), it->second.end(), greater <pair <int, int>>());
        while(it->second.size()>2) it->second.pop_back();
    }

    memset(DP, -1, sizeof(DP));
    value = find_max(0, 0);

    recover(0, 0);

    cout << find_max(0,0) << '\n';
    cout << answer.size() << '\n';
    for(pair <int, int> item: answer)
    {
        cout << item.first + 1 << " " << item.second + 1 << '\n';
    }
}

