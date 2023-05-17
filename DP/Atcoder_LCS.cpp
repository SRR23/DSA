
// Find length of LCS, and print it

#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
int dp[N][N];
int n, m;
string a, b;

int LCS(int i, int j)
{
    if (i == n || j == m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (a[i] == b[j])
    {
        int ans = 1 + LCS(i + 1, j + 1);
        return dp[i][j] = ans;
    }
    int ans = max(LCS(i + 1, j), LCS(i, j + 1));
    return dp[i][j] = ans;
}

void print(int i, int j)
{
    if (i == n || j == m)
    {
        return;
    }

    if (a[i] == b[j])
    {
        cout << a[i];
        print(i + 1, j + 1);
        return;
    }
    int x = LCS(i + 1, j);
    int y = LCS(i, j + 1);
    if (x >= y)
    {

        print(i + 1, j);
    }
    else
    {
        print(i, j + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    n = a.size();
    m = b.size();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }
    print(0, 0);
}