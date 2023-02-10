#include <bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        char now = s[i];
        if (now >= '0' && now <= '9')
        {
            ans += now;
        }
        else if (now == '(')
        {
            st.push(now);
        }
        else if (now == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (st.size() && prec(st.top()) >= prec(now))
            {
                ans += st.top();
                st.pop();
            }
            st.push(now);
        }
    }
    while (st.size())
    {
        ans += st.top();
        st.pop();
    }

    stack<int> st2;

    for (int i = 0; i < ans.size(); i++)
    {
        char ch = ans[i];
        if (ch >= '0' && ch <= '9')
        {
            st2.push(ch - '0');
        }
        else
        {
            int x = st2.top();
            st2.pop();
            int y = st2.top();
            st2.pop();
            switch (ch)
            {
            case '+':
                st2.push(y + x);
                break;
            case '-':
                st2.push(y - x);
                break;
            case '*':
                st2.push(y * x);
                break;
            case '/':
                st2.push(y / x);
                break;
            }
        }
    }
    cout << st2.top() << '\n';

    return 0;
}