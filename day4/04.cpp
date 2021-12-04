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
    ifstream is("04.txt");
    string temp, tt;
    vector<int> nums;
    getline(is, temp);
    stringstream st(temp);
    while (getline(st, tt, ','))
        nums.push_back(stoi(tt));
    vector<vector<pair<bool, int>>> boards;

    while (!is.eof())
    { // Making boards
        vector<pair<bool, int>> b;
        getline(is, temp, '\n');
        for (int i = 0; i < 5; i++)
        {
            getline(is, temp, '\n');
            for (int j = 0; j < 5; j++)
            {
                if (temp[j * 3] == ' ')
                    temp[j * 3] = '0';
                b.push_back(make_pair(false, stoi(temp.substr(j * 3, 2))));
            }
        }
        boards.push_back(b);
    }

    bool win = false;
    for (int i = 0; i < nums.size() && !win; i++)
    {
        for (int j = 0; j < boards.size() && !win; j++)
        { // Change vals & check win
            for (int k = 0; k < 25; k++)
                if (boards[j][k].second == nums[i])
                    boards[j][k].first = true;
            for (int k = 0; k < 5 && !win; k++)
            {
                if ((boards[j][k * 5 + 0].first &&
                     boards[j][k * 5 + 1].first &&
                     boards[j][k * 5 + 2].first &&
                     boards[j][k * 5 + 3].first &&
                     boards[j][k * 5 + 4].first) ||
                    (boards[j][k + 5 * 0].first &&
                     boards[j][k + 5 * 1].first &&
                     boards[j][k + 5 * 2].first &&
                     boards[j][k + 5 * 3].first &&
                     boards[j][k + 5 * 4].first))
                {
                    int score = 0;
                    for (int l = 0; l < 25; l++)
                        if (!boards[j][l].first)
                            score += boards[j][l].second;
                    score *= nums[i];
                    cout << score << "\n";
                    win = true;
                }
            }
        }
    }

    vector<int> wins;
    for (int i = 0; i < boards.size(); i++)
        for (int j = 0; j < 25; j++)
            boards[i][j].first = false;
    for (int i = 0; i < nums.size() && wins.size() != boards.size(); i++)
    {
        for (int j = 0; j < boards.size(); j++)
        { // Change vals & check win
            if (count(wins.begin(), wins.end(), j))
                continue;
            for (int k = 0; k < 25; k++)
                if (boards[j][k].second == nums[i])
                    boards[j][k].first = true;
            for (int k = 0; k < 5; k++)
            {
                if ((boards[j][k * 5 + 0].first &&
                     boards[j][k * 5 + 1].first &&
                     boards[j][k * 5 + 2].first &&
                     boards[j][k * 5 + 3].first &&
                     boards[j][k * 5 + 4].first) ||
                    (boards[j][k + 5 * 0].first &&
                     boards[j][k + 5 * 1].first &&
                     boards[j][k + 5 * 2].first &&
                     boards[j][k + 5 * 3].first &&
                     boards[j][k + 5 * 4].first))
                {
                    wins.push_back(j);
                    if (wins.size() == boards.size())
                    {
                        int score = 0;
                        for (int l = 0; l < 25; l++)
                            if (!boards[j][l].first)
                                score += boards[j][l].second;
                        score *= nums[i];
                        cout << score << "\n";
                    }
                }
            }
        }
    }

    return 0;
}