
// dfs + dp on grid

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dp;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool is_inside(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        return true;
    }

    bool ok(int i, int j, int k, int l, vector<vector<int>> &grid)
    {
        if (grid[i][j] <= grid[k][l])
        {
            return false;
        }
        return true;
    }

    int dfs(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (is_inside(x, y, n, m) && ok(x, y, i, j, grid))
            {
                ans = max(ans, 1 + dfs(x, y, n, m, grid));
            }
        }
        return dp[i][j] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, dfs(i, j, n, m, matrix));
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // take input from users
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            tmp.push_back(val);
        }
        v.push_back(tmp);
    }

    Solution func;
    cout << func.longestIncreasingPath(v) << '\n';
}