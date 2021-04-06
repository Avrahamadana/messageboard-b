#include "Direction.hpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;

namespace ariel
{
    class Board
    {
    private:
        map<unsigned int, map<unsigned int, string>> board;
        int max_row;
        int max_col;

    public:
        void post(unsigned int row, unsigned int colum, Direction d, string s);
        string read(unsigned int row, unsigned int colum, Direction d, unsigned int length);
        void show();
        Board(/* args */);
        ~Board();
    };

}
