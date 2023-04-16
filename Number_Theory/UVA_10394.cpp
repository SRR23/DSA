
// Twin primes are pairs of primes of the form (p, p + 2)
// In this problem you are asked to find out the S-th twin prime
// pair where S is an integer that will be given in the input

#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
bitset<N> is_prime;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i < N; i++)
    {
        is_prime[i] = true;
    }

    for (int i = 2; 1LL * i * i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = 1LL * i * i; j < N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i + 2 < N; i++)
    {
        if (is_prime[i] && is_prime[i + 2])
        {
            v.push_back({i, i + 2});
        }
    }

    int n;
    while (cin >> n)
    {
        cout << "(" << v[n - 1].first << ", " << v[n - 1].second << ")" << '\n';
    }
}