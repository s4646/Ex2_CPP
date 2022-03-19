#include "doctest.h"
#include "Notebook.hpp";
#include "Direction.hpp";

using namespace ariel;


Notebook notebook;

/* GOOD INPUT */

TEST_CASE("WRITE")
{
    // Write in a single row
    CHECK_NOTHROW(notebook.write(0,0,0,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(notebook.write(0,0,4,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(notebook.write(0,0,8,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(notebook.write(0,0,12,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(notebook.write(0,0,16,Direction::Horizontal,"abcd"));
    /*new page*/
    CHECK_NOTHROW(notebook.write(1,3,0,Direction::Horizontal,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,3,4,Direction::Horizontal,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,3,8,Direction::Horizontal,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,3,12,Direction::Horizontal,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,3,16,Direction::Horizontal,"!@#$"));

    // Write in a single column
    CHECK_NOTHROW(notebook.write(0,1,0,Direction::Vertical,"abcd"));
    CHECK_NOTHROW(notebook.write(0,5,0,Direction::Vertical,"abcd"));
    CHECK_NOTHROW(notebook.write(0,9,0,Direction::Vertical,"abcd"));
    CHECK_NOTHROW(notebook.write(0,13,0,Direction::Vertical,"abcd"));
    CHECK_NOTHROW(notebook.write(0,17,0,Direction::Vertical,"abcd"));
    /*newpage*/
    CHECK_NOTHROW(notebook.write(1,4,23,Direction::Vertical,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,8,23,Direction::Vertical,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,12,23,Direction::Vertical,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,16,23,Direction::Vertical,"!@#$"));

    // Diangonal writing
    CHECK_NOTHROW(notebook.write(0,1,2,Direction::Horizontal,"a"));
    CHECK_NOTHROW(notebook.write(0,2,3,Direction::Horizontal,"ab"));
    CHECK_NOTHROW(notebook.write(0,3,5,Direction::Horizontal,"abc"));
    CHECK_NOTHROW(notebook.write(0,4,8,Direction::Horizontal,"abcd"));
    /*new page*/
    CHECK_NOTHROW(notebook.write(1,4,24,Direction::Horizontal,"!"));
    CHECK_NOTHROW(notebook.write(1,5,25,Direction::Horizontal,"!@"));
    CHECK_NOTHROW(notebook.write(1,6,27,Direction::Horizontal,"!@#"));
    CHECK_NOTHROW(notebook.write(1,7,30,Direction::Horizontal,"!@#$"));

}

TEST_CASE("READ")
{
    // Read horizontally
    CHECK(notebook.read(0,0,0,Direction::Horizontal,4) == "abcd");
    CHECK(notebook.read(0,1,2,Direction::Horizontal,1) =="a");
    CHECK(notebook.read(0,2,3,Direction::Horizontal,2) == "ab");
    CHECK(notebook.read(0,3,5,Direction::Horizontal,3) == "abc");
    /*new page*/
    CHECK(notebook.read(1,4,24,Direction::Horizontal,4) == "!@#$");
    CHECK(notebook.read(1,5,25,Direction::Horizontal,1) =="!");
    CHECK(notebook.read(1,6,27,Direction::Horizontal,2) == "!@");
    CHECK(notebook.read(1,7,30,Direction::Horizontal,3) == "!@#");

    // Read vertically
    CHECK(notebook.read(0,1,0,Direction::Vertical,4) == "abcd");
    CHECK(notebook.read(0,5,0,Direction::Vertical,1) =="a");
    CHECK(notebook.read(0,6,0,Direction::Vertical,2) == "bc");
    CHECK(notebook.read(0,8,1,Direction::Vertical,3) == "_");
    /*new page*/
    // CHECK(notebook.read(1,4,24,Direction::Vertical,4) == "!@#$");
    // CHECK(notebook.read(1,5,25,Direction::Vertical,1) =="!");
    // CHECK(notebook.read(1,6,27,Direction::Vertical,2) == "!@");
    // CHECK(notebook.read(1,7,30,Direction::Vertical,3) == "!@#");



}

TEST_CASE("ERASE")
{

}

TEST_CASE("SHOW")
{

}

/* GOOD INPUT */


/* BAD INPUT */
/* BAD INPUT */