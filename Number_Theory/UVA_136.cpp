
// Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
// Write a program to find and print the 1500’th ugly number.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ll> v;
    for (ll p2 = 1; p2 <= N; p2 *= 2)
    {
        for (ll p3 = 1; p2 * p3 <= N; p3 *= 3)
        {
            for (ll p5 = 1; p2 * p3 * p5 <= N; p5 *= 5)
            {
                v.push_back(p2 * p3 * p5);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << "The 1500'th ugly number is " << v[1500 - 1] << ".\n";
}