
// Remove adjacent same characters using stack

#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    string ans = "meow";
    while (t--)
    {
        stack<char> st;
        int n;
        cin >> n;
        string s, s1;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || st.top() != s[i])
            {
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            s1.push_back(st.top());
            st.pop();
        }
        reverse(s1.begin(), s1.end());
        if (s1 == ans)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}