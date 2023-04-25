
// You are given two positive integers – A and B. You have to check
// whether A is divisible by all the prime divisors of B

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
        ll a, b;
        cin >> a >> b;
        while (1)
        {
            ll gcd = __gcd(a, b);
            if (gcd == 1)
            {
                break;
            }
            b /= gcd;
        }
        if (b == 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}