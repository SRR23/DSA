
// Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int l = 0, r = 0;
        int mx = 0, uniq = 0;
        int freq[26] = {0};
        string ans;
        while (r < n)
        {
            if (ans.find(s[r]) == string::npos)
            {
                uniq++;
            }
            ans.push_back(s[r]);
            int len = ans.size();
            if (len > uniq)
            {
                mx = max(mx, uniq);
                ans.erase(ans.begin() + 0);
                ans.pop_back();
                uniq--;
                r--;
            }
            r++;
        }
        return max(mx, uniq);
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
    cout << func.lengthOfLongestSubstring(s) << '\n';
}