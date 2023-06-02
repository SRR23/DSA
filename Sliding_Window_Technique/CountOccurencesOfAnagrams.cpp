
/*
Given a word pat and a text txt. Return the count of the 
occurences of anagrams of the word in the text
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(string pat, string txt)
    {
        int l = 0, r = 0;
        int k = pat.size();
        int n = txt.size();
        int freq1[26] = {0};
        int freq2[26] = {0};
        for (int i = 0; i < pat.size(); i++)
        {
            freq1[pat[i] - 'a']++;
        }
        int cnt = 0;
        while (r < n)
        {
            freq2[txt[r] - 'a']++;
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
                    cnt++;
                }
                freq2[txt[l] - 'a']--;
                l++;
                r++;
            }
        }
        return cnt;
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
    cout << func.search(p, s) << '\n';
}