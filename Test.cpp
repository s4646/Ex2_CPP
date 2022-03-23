#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"

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
    CHECK_NOTHROW(notebook.write(1,3,16,Direction::Vertical,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,7,16,Direction::Vertical,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,11,16,Direction::Vertical,"!@#$"));
    CHECK_NOTHROW(notebook.write(1,15,16,Direction::Vertical,"!@#$"));

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
    CHECK_NOTHROW(notebook.write(1,11,6,Direction::Horizontal,"!@#$"));

    // Art
    /* page 2 */
    CHECK_NOTHROW(notebook.write(2,0,0,Direction::Horizontal,"_____0000_____________0000________7777777777777777/==================="));
    CHECK_NOTHROW(notebook.write(2,1,0,Direction::Horizontal,"___00000000_________00000000______7777^^^^^^^7777/_||_||              "));
    CHECK_NOTHROW(notebook.write(2,2,0,Direction::Horizontal,"__000    000_______000    000_____777       7777/=========//=========="));
    CHECK_NOTHROW(notebook.write(2,3,0,Direction::Horizontal,"_000      000_____000      000____         7777//_((_____//"));
    CHECK_NOTHROW(notebook.write(2,4,0,Direction::Horizontal,"0000      0000___0000      0000___        7777//___\\___//"));
    CHECK_NOTHROW(notebook.write(2,5,0,Direction::Horizontal,"0000      0000___0000      0000___       7777//========//"));
    CHECK_NOTHROW(notebook.write(2,6,0,Direction::Horizontal,"0000      0000___0000      0000___      7777"));
    CHECK_NOTHROW(notebook.write(2,7,0,Direction::Horizontal,"0000      0000___0000      0000___     7777"));
    CHECK_NOTHROW(notebook.write(2,8,0,Direction::Horizontal,"_000      000_____000      000____    7777"));
    CHECK_NOTHROW(notebook.write(2,9,0,Direction::Horizontal,"__000    000_______000    000_____  77777"));
    CHECK_NOTHROW(notebook.write(2,10,0,Direction::Horizontal,"___00000000_________00000000______ 7777777"));
    CHECK_NOTHROW(notebook.write(2,11,0,Direction::Horizontal,"_____0000_____________0000________777777777"));
    /*page 3*/
    /* 
    ___..eeeee..___
    _e8"___8___"8e_
    d8_____8_____8b
    8!___.dWb.___!8
    Y8_.e*_8_*e._8P
    _*8*___8___*8*_
    ___**ee8ee**___
    */
    CHECK_NOTHROW(notebook.write(3,0,3,Direction::Horizontal,"..ee"));
    CHECK_NOTHROW(notebook.write(3,0,8,Direction::Horizontal,"ee.."));
    
    CHECK_NOTHROW(notebook.write(3,1,1,Direction::Horizontal,"e8\""));
    CHECK_NOTHROW(notebook.write(3,1,12,Direction::Horizontal,"\"8e"));

    CHECK_NOTHROW(notebook.write(3,2,0,Direction::Horizontal,"d8"));
    CHECK_NOTHROW(notebook.write(3,2,13,Direction::Horizontal,"8b"));

    CHECK_NOTHROW(notebook.write(3,3,0,Direction::Horizontal,"8!___.d"));
    CHECK_NOTHROW(notebook.write(3,3,8,Direction::Horizontal,"b.___!8"));

    CHECK_NOTHROW(notebook.write(3,4,0,Direction::Horizontal,"Y8_.e*_"));
    CHECK_NOTHROW(notebook.write(3,4,8,Direction::Horizontal,"_*e._8P"));
    
    CHECK_NOTHROW(notebook.write(3,5,0,Direction::Horizontal,"Y8_.e*_"));
    CHECK_NOTHROW(notebook.write(3,5,8,Direction::Horizontal,"_*e._8P"));

    CHECK_NOTHROW(notebook.write(3,6,1,Direction::Horizontal,"*8*"));
    CHECK_NOTHROW(notebook.write(3,6,11,Direction::Horizontal,"*8*"));

    CHECK_NOTHROW(notebook.write(3,7,3,Direction::Horizontal,"**ee"));
    CHECK_NOTHROW(notebook.write(3,7,8,Direction::Horizontal,"ee**"));

    CHECK_NOTHROW(notebook.write(3,0,7,Direction::Vertical,"e88W888"));
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
    /*page 2*/
    CHECK(notebook.read(2,0,5,Direction::Horizontal,5) == "0000_");
    CHECK(notebook.read(2,2,19,Direction::Horizontal,29) == "000    000_____777       7777");

    // Read vertically
    /*page 0*/
    CHECK(notebook.read(0,1,0,Direction::Vertical,4) == "abcd");
    CHECK(notebook.read(0,5,0,Direction::Vertical,1) =="a");
    CHECK(notebook.read(0,6,0,Direction::Vertical,2) == "bc");
    CHECK(notebook.read(0,8,1,Direction::Vertical,3) == "___");
    /*page 1*/
    CHECK(notebook.read(1,2,16,Direction::Vertical,4) == "_!@#");
    CHECK(notebook.read(1,7,16,Direction::Vertical,1) =="!");
    CHECK(notebook.read(1,8,16,Direction::Vertical,2) == "@#");
    CHECK(notebook.read(1,10,16,Direction::Vertical,3) == "$!@");
    /*page 2*/
    CHECK(notebook.read(2,5,0,Direction::Vertical,5) == "000__");
    CHECK(notebook.read(2,9,5,Direction::Vertical,3) == " 00");
}

TEST_CASE("ERASE")
{
    /*page 0*/
    CHECK_NOTHROW(notebook.erase(0,13,0,Direction::Vertical,4));
    CHECK_NOTHROW(notebook.erase(0,1,2,Direction::Vertical,2));
    CHECK_NOTHROW(notebook.erase(0,0,0,Direction::Horizontal,4));
    CHECK_NOTHROW(notebook.erase(0,4,8,Direction::Horizontal,1));
    /*page 1*/
    CHECK_NOTHROW(notebook.erase(1,3,6,Direction::Vertical,4));
    CHECK_NOTHROW(notebook.erase(1,8,0,Direction::Vertical,2));
    CHECK_NOTHROW(notebook.erase(1,18,0,Direction::Horizontal,4));
    CHECK_NOTHROW(notebook.erase(1,18,5,Direction::Horizontal,1));
}
/* GOOD INPUT */


/* BAD INPUT */
TEST_CASE("WRITE")
{
    /*page 0*/
    CHECK_THROWS(notebook.write(0,0,0,Direction::Horizontal,"abcd"));
    CHECK_THROWS(notebook.write(0,0,4,Direction::Horizontal,"fdsa"));
    CHECK_THROWS(notebook.write(0,0,0,Direction::Horizontal,"ab"));
    CHECK_THROWS(notebook.write(0,4,8,Direction::Horizontal,"W"));
    /*page 1*/
    CHECK_THROWS(notebook.write(1,4,16,Direction::Vertical,"!@#$"));
    CHECK_THROWS(notebook.write(1,8,16,Direction::Vertical,"mvkf"));
    CHECK_THROWS(notebook.write(1,3,6,Direction::Vertical,"LOL"));
    CHECK_THROWS(notebook.write(1,8,0,Direction::Vertical,"Qw"));

    /*negative input*/
    CHECK_THROWS(notebook.write(-1,0,0,Direction::Horizontal,"abcd"));
    CHECK_THROWS(notebook.write(1,-1,4,Direction::Horizontal,"fdsa"));
    CHECK_THROWS(notebook.write(2,0,-1,Direction::Horizontal,"ab"));
    CHECK_THROWS(notebook.write(-12,-3,-4,Direction::Horizontal,"W"));

}

TEST_CASE("READ")
{
    /*negative input*/
    CHECK_THROWS(notebook.read(-1,0,0,Direction::Horizontal,4));
    CHECK_THROWS(notebook.read(1,-1,4,Direction::Horizontal,4));
    CHECK_THROWS(notebook.read(2,0,-1,Direction::Vertical,2));
    CHECK_THROWS(notebook.read(-12,-3,-4,Direction::Vertical,1));
}

TEST_CASE("ERASE")
{
    /*exceeding*/
    CHECK_THROWS(notebook.erase(1,4,99,Direction::Horizontal,4));
    CHECK_THROWS(notebook.erase(1,8,98,Direction::Horizontal,4));
    CHECK_THROWS(notebook.erase(1,3,201,Direction::Horizontal,3));
    CHECK_THROWS(notebook.erase(1,8,100,Direction::Horizontal,2));

    /*negative*/
    CHECK_THROWS(notebook.erase(-1,0,0,Direction::Vertical,4));
    CHECK_THROWS(notebook.erase(1,-1,4,Direction::Vertical,4));
    CHECK_THROWS(notebook.erase(2,0,-1,Direction::Horizontal,2));
    CHECK_THROWS(notebook.erase(-12,-3,-4,Direction::Horizontal,1));
}
/* BAD INPUT */

    /* page 0
            ~~~~abcdabcdabcd
            a_~_____________
            b_~ab___________
            c____abc________
            d_______~bcd____
            a_______________
            b_______________
            c_______________
            d_______________
            a_______________
            b_______________
            c_______________
            d_______________
            ~_______________
            ~_______________
            ~_______________
            ~_______________
    */
    /* page 1
            _________________
            _________________
            !@#$!@#$!@#$!@#$_
            ______~_________!
            ______~_________@
            ______~_________#
            ______~_________$
            ________________!
            ~_______________@
            ~!@_____________#
            ___!@#__________$
            ______!@#$______!
            ________________@
            ________________#
            ________________$
            ________________!
            ________________@
            ________________#
            ~~~~_~__________$
    */
    /* page 2
        _____0000_____________0000________7777777777777777/===================
        ___00000000_________00000000______7777^^^^^^^7777/_||_||              
        __000    000_______000    000_____777       7777/=========//==========
        _000      000_____000      000____         7777//_((_____//___________
        0000      0000___0000      0000___        7777//___\\___//____________
        0000      0000___0000      0000___       7777//========//_____________
        0000      0000___0000      0000___      7777__________________________
        0000      0000___0000      0000___     7777___________________________
        _000      000_____000      000____    7777____________________________
        __000    000_______000    000_____  77777_____________________________
        ___00000000_________00000000______ 7777777_____________________________
        ____ 0000_____________0000________777777777____________________________
    */
    /* page 3
        ___..eeeee..___
        _e8"___8___"8e_
        d8_____8_____8b
        8!___.dWb.___!8
        Y8_.e*_8_*e._8P
        _*8*___8___*8*_
        ___**ee8ee**___
    */