#include <bits/stdc++.h>
using namespace std;

// Regular class
class student
{
public:
    string name;
    int roll;
    int age;
    string F_name;
    string M_name;

    void print()
    {
        cout << name << " " << roll << " " << age << " " << F_name << " " << M_name << '\n';
    }
};

// Recursive class
class person
{
public:
    string name;
    person *father, *mother;

    void print()
    {
        cout << name << " " << father->name << " " << mother->name << '\n';
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    student s;
    s.name = "Rimon";
    s.roll = 1918005;
    s.age = 23;
    s.F_name = "MD.Ismail Hossain";
    s.M_name = "Fatema Yasmine";
    s.print();

    /* person p;
    p.father = new person;
    p.mother = new person;
    p.name = "Rimon";
    p.father->name = "MD.Ismail Hossain";
    p.mother->name = "Fatema Yasmine";
    p.print(); */
}