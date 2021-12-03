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
    ifstream is("03.txt");
    vector<int> v(12, 0);
    while (!is.eof())
    {
        string s;
        is >> s;
        for (int i = 0; i < 12; i++)
        {
            if (s[i] == '1')
                v[i]++;
            else if (s[i] == '0')
                v[i]--;
        }
    }
    string gamma = "";
    string epsilon = "";
    for (int i = 0; i < 12; i++)
    {
        if (v[i] > 0)
        {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
        else if (v[i] < 0)
        {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
    }
    cout << stoi(gamma, 0, 2) * stoi(epsilon, 0, 2) << "\n";

    ifstream is2("03.txt");
    //   <most common>    <least common>  <temp vector>   <compare vector>
    tuple<vector<string>, vector<string>, vector<string>, vector<string>> p;
    int common = 0;
    while(!is2.eof())
    {
        string s;
        is2 >> s;
        get<0>(p).push_back(s);
        get<1>(p).push_back(s);
    }
    for (int pos = 0; pos < 12; pos++)
    {
        // OXY
        get<3>(p) = get<0>(p);
        get<0>(p).clear();
        for (int i = 0; i < get<3>(p).size() && get<3>(p).size() > 1; i++)
        {
            if (get<3>(p)[i][pos] == '1')
            {
                common++;
                get<0>(p).push_back(get<3>(p)[i]);
            }
            else if (get<3>(p)[i][pos] == '0')
            {
                common--;
                get<2>(p).push_back(get<3>(p)[i]);
            }
        }
        if (common < 0) // get<2> contains most common
            get<0>(p).swap(get<2>(p));
        get<2>(p).clear();
        common = 0;

        // CO2
        get<3>(p) = get<1>(p);
        get<1>(p).clear();
        for (int i = 0; i < get<3>(p).size() && get<3>(p).size() > 1; i++)
        {
            if (get<3>(p)[i][pos] == '1')
            {
                common++;
                get<2>(p).push_back(get<3>(p)[i]);
            }
            else if (get<3>(p)[i][pos] == '0')
            {
                common--;
                get<1>(p).push_back(get<3>(p)[i]);
            }
        }
        if (common < 0) // get<2> contains most common
            get<1>(p).swap(get<2>(p));
        get<2>(p).clear();
        common = 0;
    }
    cout << stoi(get<0>(p)[0], 0, 2) * stoi(get<1>(p)[0], 0, 2) << "\n";

    return 0;
}