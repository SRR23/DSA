#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<char> dq;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        dq.push_back(s[i]);
    }

    while (dq.size() > 1)
    {
        if (dq.front() == dq.back())
        {
            dq.pop_front();
            dq.pop_back();
        }
        else
        {
            break;
        }
    }

    if (dq.size() <= 1)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}