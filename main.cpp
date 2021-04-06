#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;
template <typename K, typename V>
void print_map(map<K, V> const &m)
{
    for (auto const &pair : m)
    {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

void print1_map(map<int, map<int, char>> const &m)
{
}
map<int, map<int, string>> board1;

void post(unsigned int row, unsigned int colum, int d, string s)
{
    int j = 0;
    unsigned int colump = colum;
    unsigned int rowp = row;
    if (d == 1)
    {
        for (unsigned int k = 0; k < s.length(); k++)
        {
            board1[(int)row][(int)colump] = s.at(k);
            colump = colump + 1;
        }
        return;
    }
    else
    {
        for (unsigned int k = 0; k < s.length(); k++)
        {
            board1[(int)rowp][(int)colum] = s.at(k);
            rowp = rowp + 1;
        }
        return;
    }
}

string read(unsigned int row, unsigned int colum, int d, unsigned int length)
{
    string s;
    unsigned int colump = colum;
    unsigned int rowp = row;
    if (d == 1)
    {
        for (unsigned int i = 0; i < length; i++)
        {
            if (board1[row][(int)colump].empty())
            {
                board1[(int)row][(int)colump] = '_';
            }
            s += board1[(int)row][(int)colump];
            colump = colump + 1;
        }
    }
    else
    {
        for (unsigned int i = 0; i < length; i++)
        {
            if (board1[(int)rowp][(int)colum].empty())
            {
                board1[(int)rowp][(int)colum] = '_';
            }
            s += board1[(int)rowp][(int)colum];
            rowp = rowp + 1;
        }
    }
    return s;
}

int main()
{
    map<int, map<int, char>> m;
    // map<int, char> m1;
    // string s = "avraham";
    // char c[4] = {'a', 'l', 'o', 'n'};
    // for (int i = 0; i < s.length(); i++)
    // {
    //     m1[i] = s.at(i);
    // };
    // post(0, 0, 0, "avraham");
    // post(5, 6, 1, "alon");
    // string t = read(5, 6, 1, 8);
    // for (int i = 0; i < t.length(); i++)
    // {
    //     printf("%c", t.at(i));
    //     // printf("IN FOR !");
    // }
    // printf("\n");
    // string f = read(0, 0, 0, 3);
    // for (int i = 0; i < f.length(); i++)
    // {
    //     printf("%c", f.at(i));
    // }
    // printf("%s",t);
    m[0][0] = 'a';
    m[0][1] = 'l';
    m[0][2] = 'o';
    m[0][3] = 'n';
    m[1][0] = 'v';
    m[2][0] = 'r';
    m[3][0] = 'h';
    m[4][0] = 'a';
    m[5][0] = 'm';
    m[1][1] = 'i';
    m[2][1] = 'o';
    m[3][1] = 'r';
    m[1][4] = 'z';
    map<int, map<int, char> >::iterator itr;
    map<int, char>::iterator ptr;

    for (itr = m.begin(); itr != m.end(); itr++)
    {
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
        {
            cout <<ptr->second;
        }
        printf("\n");
    }

    // char sr = m[0][4];
    // printf("%c",sr);
    // map<int,map<int,char>> m;
    // map<int,char> m1;
    // m1[5] = 'a';
    // m1[6] = 'l';
    // m1[7] = 'o';
    // m1[8] = 'n';
    // m[5] = m1;
    // map<int, string> r;
    // r[5] = m[6][0];
    // print_map(r);
    // m1[0] = 'z';
    // m1[1] = 'm';
    // print_map(m1);
    // print1_map(m);

    // printf("%c",s);
    return 0;
}