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
        priority_queue<int> pq;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        for (auto it : mp)
        {
            pq.push(it.second);
        }
        while (!pq.empty())
        {
            if (pq.size() >= 2)
            {
                int x = pq.top();
                pq.pop();
                int y = pq.top();
                pq.pop();
                if (x > 0 && y > 0)
                {
                    x--;
                    y--;
                    if (x > 0)
                    {
                        pq.push(x);
                    }
                    if (y > 0)
                    {
                        pq.push(y);
                    }
                }
            }
            else
            {
                break;
            }
        }
        if (pq.empty())
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << pq.top() << '\n';
        }
    }
    return 0;
}