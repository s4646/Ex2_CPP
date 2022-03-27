#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>
#include <stdexcept>
#include "Notebook.hpp"
#include "Direction.hpp"

using namespace std;
using namespace ariel;

/* constructors & destructors */
Page::Page() {};
Page::~Page() {};
Notebook::Notebook() {};
Notebook::~Notebook() {};
/* constructors & destructors */

void stringValidation(const string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        char tmp = str.at(i);
        if(tmp < ' ' || tmp > '}')
        {
             throw invalid_argument("unprintable char detected");
        }
    }
}

/*  write:
    receives page, row, column, direction and string as input.
    writes chars in the page at the row, column and the string's length boundaries.
    writing is performed in the given direction. 
*/
void Notebook::write(int page, int row, int column, ariel::Direction direction,const string& str)
{
    cout << "WRITE " << "page: " << page << " row: " << row << " column: " << column << " string's length: " << str.length() << endl;
    stringValidation(str);
    // invalid argument received
    if(page < 0 || row < 0 || column < 0 || column > 99)
    {
        throw invalid_argument("input is out of bounds");
    }
    // str exceeds the row's length
    if((size_t)column+str.length()>rowLength && direction==Direction::Horizontal)
    {
        throw runtime_error("writing out of row's bounds");
    }
    // page does not exist
    if(this->pages.find(page)==this->pages.end())
    {
        Page newPage;
        this->pages.insert({page,newPage});
    }

    Page& p = this->pages.at(page);
    if(direction==Direction::Horizontal)
    {
        // row does not exist
        if(p.rows.find(row)==p.rows.end())
        {
            string newRow(rowLength,'_');
            p.rows.insert({row,newRow});
        }
        string emptyStr(str.length(),'_');
        
        // check that chars to write are not empty
        if(p.rows.at(row).substr((size_t)column,str.length()) != emptyStr)
        {
            throw runtime_error("writing intersection");
        }
        // write horizontally
        p.rows.at(row).replace((size_t)column,str.length(), str);
    }
    else
    {
        int length = str.length();
        // check that chars to write are not empty
        for (int i = 0; i < length; i++)
        {
            // row does not exist
            if(p.rows.find(row+i)==p.rows.end())
            {
                continue;
            }
            if(p.rows.at(row+i).at((size_t)column)!='_')
            {
                throw runtime_error("writing intersection");
            }
        }
        // write vertically
        for (int i = 0; i < length; i++)
        {
            // row does not exist
            if(p.rows.find(row+i)==p.rows.end())
            {
                string newRow(rowLength,'_');
                p.rows.insert({row+i,newRow});
            }
            string tmp(1,str.at((size_t)i));
            p.rows.at(row+i).replace((size_t)column,1,tmp);
        }
    }
}
/*  read:
    receives page, row, column, direction and length as input.
    reads chars that are written in the page at the row, column and length boundaries.
    reading is performed in the given direction. 
*/
string Notebook::read(int page, int row, int column, ariel::Direction direction, int length)
{
    cout << "READ " << "page: " << page << " row: " << row << " column: " << column << " string's length: " << length << endl;
    // invalid argument received
    if(page < 0 || row < 0 || column < 0 || column > 99 || length < 0)
    {
        throw invalid_argument("input is out of bounds");
    }
    // str exceeds the row's length
    if((size_t)column+(size_t)length>rowLength && direction==Direction::Horizontal)
    {
        throw runtime_error("reading out of row's bounds");
    }
    string final;
    // page does not exist
    if(this->pages.find(page)==this->pages.end())
    {
        Page newPage;
        this->pages.insert({page,newPage});
    }
    Page& p = this->pages.at(page);
    if(direction==Direction::Horizontal)
    {
        // row does not exist
        if(p.rows.find((size_t)row)==p.rows.end())
        {
            string tmp((size_t)length, '_');
            final += tmp;
        }
        else
        {
            final += p.rows.at(row).substr((size_t)column, (size_t)length);  
        }
    }
    else
    {
        for (size_t i = 0; i < length; i++)
        {
            // row does not exist
            if(p.rows.find((size_t)row+i)==p.rows.end())
            {
                final += '_';
            }
            else
            {
                final += p.rows.at((size_t)row+i).at((size_t)column);
            }
        }
    }
    return final;
}
/*  erase:
    receives page, row, column, direction and length as input.
    erases chars that are written in the page at the row, column and length boundaries.
    erasing is performed in the given direction. 
*/
void Notebook::erase(int page, int row, int column, ariel::Direction direction, int length)
{
    cout << "ERASE " << "page: " << page << " row: " << row << " column: " << column << " string's length: " << length << endl;
    // invalid argument received
    if(page < 0 || row < 0 || column < 0 || column > 99 || length < 0)
    {
        throw invalid_argument("inputis out of bounds");
    }
    // str exceeds the row's length
    if((size_t)column+(size_t)length>rowLength && direction==Direction::Horizontal)
    {
        throw invalid_argument("erasing out of row's bounds");
    }
    string str((size_t)length,'~');
    // page does not exist
    if(this->pages.find(page)==this->pages.end())
    {
        Page newPage;
        this->pages.insert({page,newPage});
    }
    Page& p = this->pages.at(page);
    if(direction==Direction::Horizontal)
    {
            // row does not exist
            if(p.rows.find(row) == p.rows.end())
            {
                string newRow(rowLength,'_');
                p.rows.insert({row,newRow});
            }
        p.rows.at(row).replace((size_t)column,(size_t)length, str);
    }
    else
    {
        int length = str.length();
        for (size_t i = 0; i < length; i++)
        {
            // row does not exist
            if(p.rows.find((size_t)row+i) == p.rows.end())
            {
                string newRow(rowLength,'_');
                p.rows.insert({(size_t)row+i,newRow});
            }
            string tmp(1,str.at(i));
            p.rows.at((size_t)row+i).replace((size_t)column,1,tmp);
        }
    }
}
/*  show:
    reveices index of a page as input.
    prints the page associated to that index.
*/
void Notebook::show(int index)
{
    // invalid argument received
    if(index < 0)
    {
        throw invalid_argument("input is out of bounds");
    }
    // page does not exist
    if(this->pages.find(index)==this->pages.end())
    {
        Page newPage;
        this->pages.insert({index,newPage});
    }
    // find the min and max row
    Page& p = this->pages.at(index);
    int maxPage = 0;
    int minPage = INT32_MAX;
    for (const auto& Pair : p.rows)
    {
        if(maxPage < Pair.first)
        {
            maxPage = Pair.first;
        }
        if(minPage > Pair.first)
        {
            minPage = Pair.first;
        }
    }
    // prevent min>max
    if(minPage == INT32_MAX)
    {
        minPage = maxPage;
    }
    string final;
    for (int i = minPage; i < maxPage + 1; i++)
    {
        // row does not exist or empty page
        if(p.rows.find(i) == p.rows.end())
        {
            string newRow(rowLength,'_');
            final += std::to_string(i) + "\t: " + newRow + "\n";
        }
        else
        {
            final += std::to_string(i) + "\t: " + p.rows.at(i) + "\n";
        }
    }
    if(!final.empty())
    {
        final.pop_back();
    }
    cout << final << endl;
}