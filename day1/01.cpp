/**
 * @author github.com/akappakappa
 * 
 */
#include <bits/stdc++.h> // Include every standard library
using namespace std;
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl

inline void OPEN(string i, string o)
{
    freopen(i.c_str(), "r", stdin);
    freopen(o.c_str(), "w", stdout);
}

int main()
{
    ifstream is("01.txt", ifstream::in);
    int count = 0;
    int prev;
    is >> prev;
    int cur;
    while (!is.eof())
    {
        is >> cur;
        if (cur > prev)
            count++;
        prev = cur;
    }
    cout << count << "\n";
    is.close();

    ifstream is2("01.txt", ifstream::in);
    count = 0;
    int p[3];
    is2 >> p[0];
    is2 >> p[1];
    is2 >> p[2];
    int c[3];
    c[0] = p[1];
    c[1] = p[2];
    while (!is2.eof())
    {
        is2 >> c[2];
        if (c[0] + c[1] + c[2] > p[0] + p[1] + p[2])
            count++;
        p[0] = c[0];
        p[1] = c[1];
        p[2] = c[2];
        c[0] = c[1];
        c[1] = c[2];
    }
    cout << count << "\n";
    is2.close();

    return 0;
}