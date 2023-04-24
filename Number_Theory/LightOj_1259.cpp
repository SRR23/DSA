
// Every even integer, greater than 2, can be expressed as the sum
// of two primes.
// Your task is to check whether this conjecture holds for integers
// up to 1e7.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 5;
bitset<N> is_prime;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i < N; i++)
    {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            v.push_back(i);
        }
    }

    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        cout << "Case " << k << ": ";
        int cnt = 0;
        for (int i = 0; v[i] + v[i] <= n; i++)
        {
            int a = v[i];
            int b = n - a;
            if (is_prime[b])
            {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}