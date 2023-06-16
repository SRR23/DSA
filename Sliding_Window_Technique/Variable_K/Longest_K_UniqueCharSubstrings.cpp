#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        int l = 0, r = 0;
        int n = s.size();
        int ans = -1, uniq = 0;
        int freq[26] = {0};
        while (r < n)
        {
            if (freq[s[r] - 'a'] == 0)
            {
                uniq++;
            }
            freq[s[r] - 'a']++;
            if (uniq > k)
            {
                while (uniq > k)
                {
                    freq[s[l] - 'a']--;
                    if (freq[s[l] - 'a'] == 0)
                    {
                        uniq--;
                    }
                    l++;
                }
            }
            if (uniq == k)
            {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int k;
    cin >> k;

    Solution func;
    cout << func.longestKSubstr(s, k) << '\n';
}