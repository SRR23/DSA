#include <bits/stdc++.h>
using namespace std;

// Regular class
class student
{
public:
    int a;
    int b;

    // Constructor
    student(int p, int q)
    {
        a = p;
        b = q;
    }

    // Normal function
    void print()
    {
        cout << a << " " << b << '\n';
    }
};

bool cmp(student x, student y)
{
    return x.a < y.a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    vector<student> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back(student(a[i], i + 1));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        v[i].print();
    }
}