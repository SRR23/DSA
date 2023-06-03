
/*
Given two strings s1 and s2, return true if s2 contains a
permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the
substring of s2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int l = 0, r = 0;
        int n = s2.size();
        int k = s1.size();
        int freq1[26] = {0};
        int freq2[26] = {0};
        for (int i = 0; i < s1.size(); i++)
        {
            freq1[s1[i] - 'a']++;
        }
        int cnt = 0;
        while (r < n)
        {
            freq2[s2[r] - 'a']++;
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
                    return true;
                }
                freq2[s2[l] - 'a']--;
                l++;
                r++;
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string p, s;
    cin >> p >> s;
    Solution func;
    if (func.checkInclusion(p, s))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }
}