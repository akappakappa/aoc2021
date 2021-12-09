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
    ifstream is("08.txt");
    int count = 0;
    while (!is.eof())
    {
        string s;
        getline(is, s, '\n');
        s = s.substr(s.find('|'));
        for (int i = 0; i < 4; i++)
        {
            s = s.substr(s.find(' ') + 1);
            if (s.substr(0, s.find(' ')).length() == 2 ||
                s.substr(0, s.find(' ')).length() == 4 ||
                s.substr(0, s.find(' ')).length() == 3 ||
                s.substr(0, s.find(' ')).length() == 7)
                count++;
        }
    }
    cout << count << " times 1, 4, 7 or 8 appear\n";

    //   0:      1:      2:      3:      4:
    //  aaaa    ....    aaaa    aaaa    ....
    // b    c  .    c  .    c  .    c  b    c
    // b    c  .    c  .    c  .    c  b    c
    //  ....    ....    dddd    dddd    dddd
    // e    f  .    f  e    .  .    f  .    f
    // e    f  .    f  e    .  .    f  .    f
    //  gggg    ....    gggg    gggg    ....
    //
    //   5:      6:      7:      8:      9:
    //  aaaa    aaaa    aaaa    aaaa    aaaa
    // b    .  b    .  .    c  b    c  b    c
    // b    .  b    .  .    c  b    c  b    c
    //  dddd    dddd    ....    dddd    dddd
    // .    f  e    f  .    f  e    f  .    f
    // .    f  e    f  .    f  e    f  .    f
    //  gggg    gggg    ....    gggg    gggg
    //
    // 0:6 1:2 2:5 3:5 4:4 5:5 6:6 7:3 8:7 9:6
    // 2:1 3:7 4:4 5:2,3,5 6:0,6,9 7:8
    ifstream is2("08.txt");
    int sum = 0;
    while (!is2.eof())
    {
        string pattern, output;
        getline(is2, output, '\n');
        pattern = output.substr(0, output.find('|') - 1);
        output = output.substr(output.find('|') + 2);
        vector<string> p, o;
        stringstream ssp(pattern), sso(output);
        string temp;
        while (getline(ssp, temp, ' '))
            p.push_back(temp);
        while (getline(sso, temp, ' '))
            o.push_back(temp);
        char sa, sb, sc, sd, se, sf, sg;

        // filling some stuff
        string t1, t4, t7, t8;
        vector<string> fiveletters, sixletters;
        for (int i = 0; i < 10; i++)
        {
            switch (p[i].length())
            {
            case 2:
                t1 = p[i];
                break;
            case 3:
                t7 = p[i];
                break;
            case 4:
                t4 = p[i];
                break;
            case 5:
                fiveletters.push_back(p[i]);
                break;
            case 6:
                sixletters.push_back(p[i]);
                break;
            case 7:
                t8 = p[i];
                break;
            }
        }

        // a is the only letter different from 1 and 7
        for (int i = 0; i < 3; i++)
            if (t1[0] != t7[i] && t1[1] != t7[i])
                sa = t7[i];
        // found: a

        // b and d are the letters different from 1 and 4
        string bd = ""; // contains what b and d could be
        for (int i = 0; i < 4; i++)
            if (t1[0] != t4[i] && t1[1] != t4[i])
                bd += t4[i];

        // out of 2,3,5 only 5 contains b, all 3 contain d
        int countbd = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                if (fiveletters[i][j] == bd[0])
                    countbd++;
        if (countbd == 1)
        { // bd[0] was b
            sb = bd[0];
            sd = bd[1];
        }
        else if (countbd == 3)
        { // bd[0] was d
            sd = bd[0];
            sb = bd[1];
        }
        // found: a b d

        // fin index of 2, index of 3, index of 5, index of 0, index of 6, indexof9
        int indexof2, indexof3, indexof5, indexof0, indexof6, indexof9;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                if (fiveletters[i][j] == sb)
                    indexof5 = i;
        for (int i = 0; i < 3; i++)
        {
            bool foundd = false;
            for (int j = 0; j < 6; j++)
                if (sixletters[i][j] == sd)
                    foundd = true;
            if (!foundd)
                indexof0 = i;
        }
        for (int i = 0; i < 3; i++)
        {
            int countcf = 0;
            for (int j = 0; j < 6; j++)
                if (sixletters[i][j] == t1[0] || sixletters[i][j] == t1[1])
                    countcf++;
            if (countcf == 1)
                indexof6 = i;
        }
        indexof9 = 3 - indexof0 - indexof6;
        for (int i = 0; i < 3; i++)
        {
            if (i == indexof5)
                continue;
            int common = 0;
            for (int j = 0; j < 5; j++)
                for (int k = 0; k < 5; k++)
                    if (fiveletters[indexof5][j] == fiveletters[i][k])
                        common++;
            if (common == 3)
                indexof2 = i;
            else if (common == 4)
                indexof3 = i;
        }
        // found: a b d i2 i3 i5 i0 i6 i9

        // e is the letter different from 8 and 9
        for (int i = 0; i < 7; i++)
        {
            bool searche = false;
            for (int j = 0; j < 6; j++)
                if (t8[i] == sixletters[indexof9][j])
                    searche = true;
            if (!searche)
                se = t8[i];
        }
        // found: a b d e i2 i3 i5 i0 i6 i9

        // e is the letter different from 8 and 6
        for (int i = 0; i < 7; i++)
        {
            bool searchc = false;
            for (int j = 0; j < 6; j++)
                if (t8[i] == sixletters[indexof6][j])
                    searchc = true;
            if (!searchc)
                sc = t8[i];
        }
        // found: a b c d e i2 i3 i5 i0 i6 i9

        // g is the letter different from 7 and (9 - bd)
        for (int i = 0; i < 6; i++)
        {
            bool searchg = false;
            for (int j = 0; j < 3; j++)
                if (sixletters[indexof9][i] != sb &&
                sixletters[indexof9][i] != sd &&
                sixletters[indexof9][i] == t7[j])
                    searchg = true;
            if (!searchg)
                sg = sixletters[indexof9][i];
        }
        // found: a b c d e g i2 i3 i5 i0 i6 i9

        // f is the other letter in 1, other than c
        t1[0] != sc ? sf = t1[0] : sf = t1[1];
        // found: a b c d e f g i2 i3 i5 i0 i6 i9

        // Time to understand the output
        for (int i = 0; i < 4; i++)
        { // Translating, sorting and calculating the output
            for (int j = 0; j < o[i].length(); j++)
            {
                switch (o[i][j])
                {
                case 'a':
                    o[i][j] = sa;
                    break;
                case 'b':
                    o[i][j] = sb;
                    break;
                case 'c':
                    o[i][j] = sc;
                    break;
                case 'd':
                    o[i][j] = sd;
                    break;
                case 'e':
                    o[i][j] = se;
                    break;
                case 'f':
                    o[i][j] = sf;
                    break;
                case 'g':
                    o[i][j] = sg;
                    break;
                }
            }
            sort(o[i].begin(), o[i].end());
            int n = -1;
            if (o[i] == "abcefg")
                n = 0;
            else if (o[i] == "cf")
                n = 1;
            else if (o[i] == "acdeg")
                n = 2;
            else if (o[i] == "acdfg")
                n = 3;
            else if (o[i] == "bcdf")
                n = 4;
            else if (o[i] == "abdfg")
                n = 5;
            else if (o[i] == "abdefg")
                n = 6;
            else if (o[i] == "acf")
                n = 7;
            else if (o[i] == "abcdefg")
                n = 8;
            else if (o[i] == "abcdfg")
                n = 9;
            sum += n * pow(10, 3 - i);
        }
    }
    cout << sum << " is the total\n";

    return 0;
}