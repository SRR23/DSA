
// Longest Palindromic Subsequence

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
    int longestPalindromeSubseq(string s)
    {
        string b = s;
        reverse(b.begin(), b.end());

        int size = s.size();

        dp.resize(size + 1, vector<int>(size + 1, -1));

        return LCS(s, b, 0, 0);
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
    cout << func.longestPalindromeSubseq(s) << '\n';
}