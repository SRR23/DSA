#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dp;

    int LCS(string &a, string &b, int i, int j)
    {
        if (i == a.size() || j == b.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (a[i] == b[j])
        {
            int ans = 1 + LCS(a, b, i + 1, j + 1);
            return dp[i][j] = ans;
        }
        int ans = max(LCS(a, b, i + 1, j), LCS(a, b, i, j + 1));
        return dp[i][j] = ans;
    }

public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.size();
        int len2 = word2.size();
        dp.resize(len1 + 1, vector<int>(len2 + 1, -1));
        int ans = LCS(word1, word2, 0, 0);
        return (len1+len2)-(2*ans);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    Solution func;
    cout<<func.minDistance(s1,s2)<<'\n';
}