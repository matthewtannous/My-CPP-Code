#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>>
        ans; // key is the sorted word, vector containes all words

    for (string &s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());
        ans[key].push_back(s);
    }

    vector<vector<string>> result;

    for (auto &entry : ans)
    {
        result.push_back(entry.second); // entry.second is a vector
    }

    return result;
}

// Other solution
vector<vector<string>> groupAnagrams2(vector<string> &strs)
{
    unordered_map<string, vector<string>> groups;

    for (const string &s : strs)
    {
        int count[26] = {0};
        for (char c : s)
        {
            count[c - 'a']++;
        }

        // Build a unique key from character counts
        string key;
        for (int i = 0; i < 26; i++)
        {
            key += '#';
            key += to_string(count[i]);
        }

        groups[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &pair : groups)
    {
        result.push_back(pair.second);
    }

    return result;
}
