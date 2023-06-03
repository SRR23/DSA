#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int l = 0, r = 0;
        int n = s.size();
        int k = p.size();
        int freq1[26] = {0};
        int freq2[26] = {0};
        for (int i = 0; i < p.size(); i++)
        {
            freq1[p[i] - 'a']++;
        }
        vector<int> v;
        while (r < n)
        {
            freq2[s[r] - 'a']++;
            if (r < k - 1)
            {
                r++;
            }
            else
            {
                bool ok = true;
                for (int i = 0; i < 26; i++)
                {
                    if (freq1[i] != freq2[i])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    v.push_back(l);
                }
                freq2[s[l] - 'a']--;
                l++;
                r++;
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

    string s, p;
    cin >> s >> p;
    Solution func;
    vector<int> ans = func.findAnagrams(s, p);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
}