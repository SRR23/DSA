#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> convert(vector<vector<int>> a)
{
    vector<vector<int>> List(a.size());
    for (int i = 0; i < a.size(); i++)
    {

        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] != 0)
            {
                List[i].push_back(j);
            }
        }
    }
    return List;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // take input from users
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            tmp.push_back(val);
        }
        v.push_back(tmp);
    }

    // insert manually

    // vector<int> p({0, 1, 1, 0, 0, 0});
    // vector<int> q({1, 0, 0, 1, 1, 0});
    // vector<int> r({1, 0, 0, 0, 0, 1});
    // vector<int> s({0, 1, 0, 0, 1, 1});
    // vector<int> t({0, 1, 0, 1, 0, 0});
    // vector<int> u({0, 0, 1, 1, 0, 0});

    // v.push_back(p);
    // v.push_back(q);
    // v.push_back(r);
    // v.push_back(s);
    // v.push_back(t);
    // v.push_back(u);

    vector<vector<int>> List = convert(v);

    for (int i = 0; i < List.size(); i++)
    {
        cout << i << ": ";
        for (int j = 0; j < List[i].size(); j++)
        {
            if (j == List[i].size() - 1)
            {
                cout << List[i][j] << '\n';
                break;
            }
            else
            {
                cout << List[i][j] << " ";
            }
        }
    }
    return 0;
}
