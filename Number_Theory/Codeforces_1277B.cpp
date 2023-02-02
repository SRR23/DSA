
// For the one move you can choose any even value c and divide by two 
// all elements that equal c.
// find the minimal number of moves for transforming a to an array 
// of only odd integers

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
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        int cnt = 0;
        while (!s.empty())
        {
            int p = *s.rbegin();
            s.erase(p);
            if (p % 2 == 0)
            {
                cnt++;
                s.insert(p / 2);
            }
        }
        cout << cnt << '\n';
    }
}