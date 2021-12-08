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
    ifstream is("05.txt");
    vector<vector<int>> field(1000);
    for (int i = 0; i < 1000; i++)
        for (int k = 0; k < 1000; k++)
            field[i].push_back(0);
    int count = 0;
    while (!is.eof())
    {
        string l;
        getline(is, l, '\n');
        int x1 = stoi(l.substr(0, l.find(',')));
        int y1 = stoi(l.substr(l.find(',') + 1, l.find(' ') - l.find(',') - 1));
        int x2 = stoi(l.substr(l.rfind(' ') + 1, l.rfind(',') - l.rfind(' ') - 1));
        int y2 = stoi(l.substr(l.rfind(',') + 1));
        if (x1 == x2 || y1 == y2)
            for (int i = min(x1, x2); i <= max(x1, x2); i++)
                for (int k = min(y1, y2); k <= max(y1, y2); k++)
                    if (++field[k][i] == 2)
                        count++;
    }
    cout << count << " spots that have more than one line\n";

    ifstream is2("05.txt");
    for (int i = 0; i < 1000; i++)
        for (int k = 0; k < 1000; k++)
            field[k][i] = 0;
    count = 0;
    while (!is2.eof())
    {
        string l;
        getline(is2, l, '\n');
        int x1 = stoi(l.substr(0, l.find(',')));
        int y1 = stoi(l.substr(l.find(',') + 1, l.find(' ') - l.find(',') - 1));
        int x2 = stoi(l.substr(l.rfind(' ') + 1, l.rfind(',') - l.rfind(' ') - 1));
        int y2 = stoi(l.substr(l.rfind(',') + 1));
        if (x1 == x2 || y1 == y2)
        {
            for (int i = min(x1, x2); i <= max(x1, x2); i++)
                for (int k = min(y1, y2); k <= max(y1, y2); k++)
                    if (++field[k][i] == 2)
                        count++;
        }
        else if (abs(x1 - x2) == abs(y1 - y2))
        {
            for (int i = 0; i <= abs(x1 - x2); i++)
            {
                if ((x1 < x2 && y1 < y2) || (x1 > x2 && y1 > y2))
                    if (++field[min(y1, y2) + i][min(x1, x2) + i] == 2)
                        count++;
                if ((x1 < x2 && y1 > y2) || (x1 > x2 && y1 < y2))
                    if (++field[min(y1, y2) + i][max(x1, x2) - i] == 2)
                        count++;
            }
        }
    }
    cout << count << " spots that have more than one line\n";

    return 0;
}