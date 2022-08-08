#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
{
    map<int, int> mp;
    for (auto item : items1)
    {
        mp[item[0]] += item[1];
    }
    for (auto item : items2)
    {
        mp[item[0]] += item[1];
    }
    vector<vector<int>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        vector<int> temp;
        temp[0] = it->first;
        temp[0] = it->second;
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    return 0;
}