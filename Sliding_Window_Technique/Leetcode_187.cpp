#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int l = 0, r = 0;
        int n = s.size();
        int k = 10;
        vector<string> v;
        map<string, int> mp;
        string str;
        while (r < n)
        {
            str.push_back(s[r]);
            if (r < k - 1)
            {
                r++;
            }
            else
            {
                mp[str]++;
                str.erase(str.begin() + 0);
                // l++;
                r++;
            }
        }
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                v.push_back(it.first);
            }
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    Solution func;
    vector<string> ans = func.findRepeatedDnaSequences(s);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
}