#include "doctest.h"
#include "Notebook.hpp";
#include "Direction.hpp";

using namespace ariel;


Notebook notebook;

/* GOOD INPUT */

TEST_CASE("WRITE")
{
    // Write in a single row
    /*page 0*/
    CHECK_NOTHROW(notebook.write(0,0,0,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(notebook.write(0,0,4,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(notebook.write(0,0,8,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(notebook.write(0,0,12,Direction::Horizontal,"abcd"));
    /*page 1*/
    CHECK_NOTHROW(notebook.write(1,2,0,Direction::Horizontal,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,2,4,Direction::Horizontal,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,2,8,Direction::Horizontal,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,2,12,Direction::Horizontal,"!@#$"));

    // Write in a single column
    /*page 0*/
    CHECK_NOTHROW(notebook.write(0,1,0,Direction::Vertical,"abcd"));
    CHECK_NOTHROW(notebook.write(0,5,0,Direction::Vertical,"abcd"));
    CHECK_NOTHROW(notebook.write(0,9,0,Direction::Vertical,"abcd"));
    CHECK_NOTHROW(notebook.write(0,13,0,Direction::Vertical,"abcd"));
    /*page 1*/
    CHECK_NOTHROW(notebook.write(1,4,16,Direction::Vertical,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,8,16,Direction::Vertical,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,12,16,Direction::Vertical,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,16,16,Direction::Vertical,"!@#$"));

    // Diangonal writing
    /*page 0*/
    CHECK_NOTHROW(notebook.write(0,1,2,Direction::Horizontal,"a"));
    CHECK_NOTHROW(notebook.write(0,2,3,Direction::Horizontal,"ab"));
    CHECK_NOTHROW(notebook.write(0,3,5,Direction::Horizontal,"abc"));
    CHECK_NOTHROW(notebook.write(0,4,8,Direction::Horizontal,"abcd"));
    /*page 1*/
    CHECK_NOTHROW(notebook.write(1,8,0,Direction::Horizontal,"!"));
    CHECK_NOTHROW(notebook.write(1,9,1,Direction::Horizontal,"!@"));
    CHECK_NOTHROW(notebook.write(1,10,3,Direction::Horizontal,"!@#"));
    CHECK_NOTHROW(notebook.write(1,11,5,Direction::Horizontal,"!@#$"));

}

TEST_CASE("READ")
{
    // Read horizontally
    /*page 0*/
    CHECK(notebook.read(0,0,0,Direction::Horizontal,4) == "abcd");
    CHECK(notebook.read(0,1,2,Direction::Horizontal,1) =="a");
    CHECK(notebook.read(0,2,3,Direction::Horizontal,2) == "ab");
    CHECK(notebook.read(0,3,5,Direction::Horizontal,3) == "abc");
    /*page 1*/
    CHECK(notebook.read(1,2,0,Direction::Horizontal,4) == "!@#$");
    CHECK(notebook.read(1,8,0,Direction::Horizontal,1) =="!");
    CHECK(notebook.read(1,9,1,Direction::Horizontal,2) == "!@");
    CHECK(notebook.read(1,10,3,Direction::Horizontal,3) == "!@#");

    // Read vertically
    /*page 0*/
    CHECK(notebook.read(0,1,0,Direction::Vertical,4) == "abcd");
    CHECK(notebook.read(0,5,0,Direction::Vertical,1) =="a");
    CHECK(notebook.read(0,6,0,Direction::Vertical,2) == "bc");
    CHECK(notebook.read(0,8,1,Direction::Vertical,3) == "___");
    /*page 1*/
    CHECK(notebook.read(1,2,16,Direction::Vertical,4) == "_!@#");
    CHECK(notebook.read(1,7,16,Direction::Vertical,1) =="!");
    CHECK(notebook.read(1,8,16,Direction::Vertical,2) == "!@");
    CHECK(notebook.read(1,10,16,Direction::Vertical,3) == "!@#");
}

TEST_CASE("ERASE")
{

}

TEST_CASE("SHOW")
{
    /* page 0
            abcdabcdabcdabcd
            a_a_____________
            b__ab___________
            c___abc_________
            d____abcd_______
            a_______________
            b_______________
            c_______________
            d_______________
            a_______________
            b_______________
            c_______________
            d_______________
            a_______________
            b_______________
            c_______________
            d_______________
    */

   /* page 1
            _________________
            _________________
            !@#$!@#$!@#$!@#$_
            ________________!
            ________________@
            ________________#
            ________________$
            ________________!
            !_______________@
            _!@_____________#
            ___!@#__________$
            ______!@#$______!
            ________________@
            ________________#
            ________________$
            ________________!
            ________________@
            ________________#
            ________________$
    */
}

/* GOOD INPUT */


/* BAD INPUT */
/* BAD INPUT */