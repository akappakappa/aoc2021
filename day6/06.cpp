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
    ifstream is("06.txt");
    vector<long long int> fish(10, 0);
    long long int count;
    while (!is.eof())
    {
        string f;
        getline(is, f, ',');
        fish[stoi(f)]++;
    }
    for (int i = 0; i < 80; i++)
    {
        fish[9] = fish[0];
        for(int i = 0; i < 8; i++)
            fish[i] = fish[i + 1];
        fish[6] += fish[9];
        fish[8] = fish[9];
    }
    for (int i = 0; i < 9; i++)
        count += fish[i];
    cout << count << " fish\n";

    for (int i = 80; i < 256; i++)
    {
        fish[9] = fish[0];
        for(int i = 0; i < 8; i++)
            fish[i] = fish[i + 1];
        fish[6] += fish[9];
        fish[8] = fish[9];
    }
    count = 0;
    for (int i = 0; i < 9; i++)
        count += fish[i];
    cout << count << " fish\n";

    return 0;
}