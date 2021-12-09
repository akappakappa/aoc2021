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
    ifstream is("07.txt");
    vector<pair<int, int>> crab; // <pos, count>
    while (!is.eof())
    {
        string c;
        getline(is, c, ',');
        int found = -1;
        for (int i = 0; i < crab.size(); i++)
            if (crab[i].first == stoi(c))
                found = i;
        if (found == -1)
            crab.push_back(make_pair<int, int>(stoi(c), 1));
        else
            crab[found].second++;
    }
    int maxpos = -1;
    for (int i = 0; i < crab.size(); i++)
        if (crab[i].first > maxpos)
            maxpos = crab[i].first;
    int minfuel = INT_MAX;
    for (int bruteforce = 0; bruteforce < maxpos; bruteforce++)
    {
        int fuel = 0;
        for (int i = 0; i < crab.size(); i++)
            fuel += abs(bruteforce - crab[i].first) * crab[i].second;
        if (fuel < minfuel)
            minfuel = fuel;
    }
    cout << minfuel << " is the least fuel we can use\n";

    minfuel = INT_MAX;
    for (int bruteforce = 0; bruteforce < maxpos; bruteforce++)
    {
        int fuel = 0;
        for (int i = 0; i < crab.size(); i++)
            fuel += (abs(bruteforce - crab[i].first) * (abs(bruteforce - crab[i].first) + 1) / 2) * crab[i].second;
        if (fuel < minfuel)
            minfuel = fuel;
    }
    cout << minfuel << " is the least fuel we can use\n";

    return 0;
}