/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "Board.hpp"

#include <iostream>

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
#include <algorithm>
#include <string>

using namespace ariel;

TEST_CASE("Good Board code")
{
    Board b;
    b.post(1, 3, Direction::Horizontal, "abcdefghij");
    CHECK(b.read(1, 3, Direction::Horizontal, 1) == "a");
    CHECK(b.read(1, 3, Direction::Horizontal, 2) == "ab");
    CHECK(b.read(1, 3, Direction::Horizontal, 3) == "abc");
    CHECK(b.read(1, 3, Direction::Horizontal, 4) == "abcd");
    CHECK(b.read(1, 3, Direction::Horizontal, 5) == "abcde");
    CHECK(b.read(1, 3, Direction::Horizontal, 6) == "abcdef");
    CHECK(b.read(1, 3, Direction::Horizontal, 7) == "abcdefg");
    CHECK(b.read(1, 3, Direction::Horizontal, 8) == "abcdefgh");
    CHECK(b.read(1, 3, Direction::Horizontal, 9) == "abcdefghi");
    CHECK(b.read(1, 3, Direction::Horizontal, 10) == "abcdefghij");

    b.post(1, 3, Direction::Vertical, "abcdefghij");
    CHECK(b.read(1, 3, Direction::Vertical, 1) == "a");
    CHECK(b.read(1, 3, Direction::Vertical, 2) == "ab");
    CHECK(b.read(1, 3, Direction::Vertical, 3) == "abc");
    CHECK(b.read(1, 3, Direction::Vertical, 4) == "abcd");
    CHECK(b.read(1, 3, Direction::Vertical, 5) == "abcde");
    CHECK(b.read(1, 3, Direction::Vertical, 6) == "abcdef");
    CHECK(b.read(1, 3, Direction::Vertical, 7) == "abcdefg");
    CHECK(b.read(1, 3, Direction::Vertical, 8) == "abcdefgh");
    CHECK(b.read(1, 3, Direction::Vertical, 9) == "abcdefghi");
    CHECK(b.read(1, 3, Direction::Vertical, 10) == "abcdefghij");

    Board c;
    c.post(4, 5, Direction::Horizontal, "abc");
    CHECK(c.read(4, 5, Direction::Horizontal, 5) == "abc__");
    CHECK(c.read(4, 5, Direction::Horizontal, 3) != "bc");

    c.post(4, 5, Direction::Vertical, "abc  ");
    CHECK(c.read(4, 5, Direction::Vertical, 5) == "abc  ");
    CHECK(c.read(4, 5, Direction::Vertical, 3) != "bc");

    Board d;
    d.post(2, 3, Direction::Vertical, "  abc  ");
    CHECK(d.read(2, 3, Direction::Vertical, 7) == "  abc  ");
    CHECK(d.read(2, 3, Direction::Vertical, 7) != "abc");
    CHECK(d.read(2, 3, Direction::Vertical, 7) != " abc  ");
    CHECK(d.read(2, 3, Direction::Vertical, 7) != "  abc");

    d.post(2, 3, Direction::Horizontal, "  abc  ");
    CHECK(d.read(2, 3, Direction::Horizontal, 7) == "  abc  ");
    CHECK(d.read(2, 3, Direction::Horizontal, 7) != "abc");
    CHECK(d.read(2, 3, Direction::Horizontal, 7) != " abc  ");
    CHECK(d.read(2, 3, Direction::Vertical, 7) != "  abc ");
}