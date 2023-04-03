
// Codeforces_1805B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> mp;
        vector<pair<char, int>> v;
        for (int i = 0; i < s.size(); i++)
        {
            // track the last index of the character
            mp[s[i]] = i + 1;
        }

        for (auto it : mp)
        {
            v.push_back({it.first, it.second});
        }
        cout << v[0].first;
        for (int i = 0; i < s.size(); i++)
        {
            if (i + 1 == v[0].second)
            {
                continue;
            }
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}