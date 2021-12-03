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
    ifstream is("02.txt");
    pair<int, int> pos(0, 0);
    while (!is.eof())
    {
        string s;
        int n;
        is >> s;
        is >> n;
        if (s.front() == 'f')
            pos.first += n;
        else if (s.front() == 'd')
            pos.second += n;
        else if (s.front() == 'u')
            pos.second -= n;
    }
    cout << pos.first * pos.second << "\n";

    ifstream is2("02.txt");
    tuple<int, int, int> p(0, 0, 0);
    while (!is2.eof())
    {
        string s;
        int n;
        is2 >> s;
        is2 >> n;
        if (s.front() == 'f')
        {
            get<0>(p) += n;
            get<1>(p) += get<2>(p) * n;
        }
        else if (s.front() == 'd')
            get<2>(p) += n;
        else if (s.front() == 'u')
            get<2>(p) -= n;
    }
    cout << get<0>(p) * get<1>(p) << "\n";

    return 0;
}