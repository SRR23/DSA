#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;
        for (auto it : nums)
        {
            mp[it]++;
        }
        vector<int> vec;
        priority_queue<pair<int, int>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        while (k--)
        {
            vec.push_back(pq.top().second);
            pq.pop();
        }
        return vec;
    }
};

int main()
{
    vector<int> a = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution s;
    vector<int> v = s.topKFrequent(a, k);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << '\n';
}