#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
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
        string s;
        cin >> s;
        int r = 1;
        char ch = s[0];
        string ans;
        while (r < n)
        {
            if (s[r] == ch)
            {
                ans.push_back(ch);
                r++;
                ch = s[r];
            }
            r++;
        }
        cout << ans << '\n';
    }
}