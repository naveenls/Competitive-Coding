#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    // complete this function

    int n=arr.size();

    int left[n];
    int right[n];

    memset(left,-1,sizeof(left));
    memset(right, -1, sizeof(right));

    stack<int> s;

    for(int i=0;i<arr.size();i++)
    {
        while(s.size() && arr[i]<arr[s.top()])
        {
            right[s.top()]=i;
            s.pop();
        }

        s.push(i);
    }

    while(s.size())
        s.pop();

    for(int i=arr.size()-1;i>=0;i--)
    {
        while(s.size() && arr[i]<arr[s.top()])
        {
            left[s.top()]=i;
            s.pop();
        }

        s.push(i);
    }

    map<int,int> range;

    vector<long> ans(n,-1);

    vector<pair<int,int> > v;

    for(int i=0;i<n;i++)
    {
        if(right[i]==-1)
            right[i]=n;

        int val=right[i]-left[i]-1;

        v.push_back({arr[i],val});    
    }

    sort(v.begin(),v.end(),greater<pair<int,int> >() );

    for(int i=0;i<v.size();i++)
    {
        int j=v[i].second;
        j--;

        while(j>=0 && ans[j]==-1)
        {
            ans[j]=v[i].first;
            j--;
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

