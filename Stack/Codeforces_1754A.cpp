#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        stack<char> st;
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == 'Q')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
        }
        if (st.empty())
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}