#include "Board.hpp"
#include <map>
#include <stdio.h>
using namespace ariel;

void Board::post(unsigned int row, unsigned int colum, Direction d, string s)
{
    int j = 0;
    unsigned int colump = colum;
    unsigned int rowp = row;
    if (d == Direction::Horizontal)
    {
        for (unsigned int k = 0; k < s.length(); k++)
        {
            board[row][colump] = s.at(k);
            colump = colump + 1;
        }
    }
    else
    {
        for (unsigned int k = 0; k < s.length(); k++)
        {
            board[rowp][colum] = s.at(k);
            rowp = rowp + 1;
        }
    }
}
string Board::read(unsigned int row, unsigned int colum, Direction d, unsigned int length)
{
    string s;
    unsigned int colump = colum;
    unsigned int rowp = row;
    if (d == Direction::Horizontal)
    {
        for (unsigned int i = 0; i < length; i++)
        {
            
            if (board[row][colump].empty())
            {
                board[row][colump] = '_';
            }
            s += board[row][colump].at(0);
            colump = colump + 1;
        }
    }
    else
    {
        for (unsigned int i = 0; i < length; i++)
        {
            if (board[rowp][colump].empty())
            {
                board[rowp][colum] = '_';
            }
                s += board[rowp][colum].at(0);
                rowp = rowp +1;
        }
    }
    return s;
}

void Board::show()
{
    map<unsigned int, map<unsigned int, string> >::iterator itr;
    map<unsigned int, string>::iterator ptr;

    for (itr = board.begin(); itr != board.end(); itr++)
    {
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
        {
            cout <<ptr->second;
        }
        cout << "\n";
    }
}

Board::Board()
{
    max_row = 0;
    max_col = 0;
}
Board::~Board()
{
}