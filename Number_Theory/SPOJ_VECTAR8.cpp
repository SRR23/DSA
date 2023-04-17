
// count how many prime numbers upto n, which doesn't consist any
// zero and all the suffix are also prime.

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
bitset<N> is_prime;
int ok[N];
int cnt_prime[N];

bool not_zero(int x)
{
    while (x)
    {
        if (x % 10 == 0)
        {
            return false;
        }
        x /= 10;
    }
    return true;
}

bool suffix_prime(int x)
{
    string str = to_string(x);
    for (int i = 0; i < str.size(); i++)
    {
        string s = str.substr(i);
        int p = stoi(s);
        if (!is_prime[p])
        {
            return false;
        }
    }
    return true;
}

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
        if (is_prime[i] && not_zero(i) && suffix_prime(i))
        {
            ok[i] = is_prime[i];
        }
    }
    for (int i = 1; i < N; i++)
    {
        cnt_prime[i] = cnt_prime[i - 1] + ok[i];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << cnt_prime[n] << '\n';
    }
}