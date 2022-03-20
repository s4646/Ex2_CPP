#include <iostream>
#include <unordered_map>
#include <string>
#include "Notebook.hpp"
#include "Direction.hpp"

using namespace std;
using namespace ariel;

/* constructors */
Page::Page() : numOfRows(0), maxRowLength(0) {};

Notebook::Notebook() : numOfPages(0) {};
/* constructors */

void Notebook::write(unsigned int page, unsigned int row, unsigned int column, ariel::Direction direction,const string& str)
{
    Page& p = this->pages.at(page);
    if(direction==Direction::Horizontal)
    {
        p.rows.at(row).replace(column,str.length(), str);
    }
    else
    {
        unsigned int length = str.length();
        for (unsigned int i = 0; i < length; i++)
        {
            string tmp(1,str.at(i));
            p.rows.at(row+i).replace(column,1,tmp);
        }
    }
}

string Notebook::read(unsigned int page, unsigned int row, unsigned int column, ariel::Direction direction, unsigned int length)
{
    string final;
    if(direction==Direction::Horizontal)
    {
        final += this->pages.at(page).rows.at(row).substr(column, column+length);   
    }
    else
    {
        for (unsigned int i = 0; i < length; i++)
        {
            final += this->pages.at(page).rows.at(row+i).at(column);
        }
    }
    return final;
}


void Notebook::show(unsigned int index)
{
    unsigned int numOfRows = this->pages.at(index).numOfRows;
    string final;
    for (unsigned int i = 0; i < numOfRows; i++)
    {
        final += this->pages.at(index).rows.at(i) + "\n";
    }
    if(!final.empty())
    {
        final.pop_back();
    }
    cout << final << endl;
}