#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>
#include "Notebook.hpp"
#include "Direction.hpp"

using namespace std;
using namespace ariel;



/* constructors */
Page::Page() : numOfRows(0) {};

Notebook::Notebook() : numOfPages(0) {};
/* constructors */

void Notebook::write(unsigned int page, unsigned int row, unsigned int column, ariel::Direction direction,const string& str)
{
    // str exceeds the row's length
    if(column+str.length()>rowLength && direction==Direction::Horizontal)
    {
        throw "writing out of row's bounds";
    }
    // page does not exist
    if(this->pages.find(page)==this->pages.end())
    {
        Page newPage;
        this->pages.insert({page,newPage});
        this->numOfPages = this->pages.size();
    }

    Page& p = this->pages.at(page);
    if(direction==Direction::Horizontal)
    {
        // row does not exist
        if(p.rows.find(row)==p.rows.end())
        {
            string newRow(rowLength,'_');
            p.rows.insert({row,newRow});
            p.numOfRows = p.rows.size();
        }
        string emptyStr(str.length(),'_');
        
        // if chars to write are not empty
        if(p.rows.at(row).substr(column,str.length()) != emptyStr)
        {
            throw "writing intersection";
        }
        p.rows.at(row).replace(column,str.length(), str);
    }
    else
    {
        unsigned int length = str.length();
        // if chars to write are not empty
        for (unsigned int i = 0; i < length; i++)
        {
            // row does not exist
            if(p.rows.find(row+i)==p.rows.end())
            {
                continue;
            }
            if(p.rows.at(row+i).at(column)!='_')
            {
                // throw "writing intersection";
                return;
            }
        }
        
        for (unsigned int i = 0; i < length; i++)
        {
            // row does not exist
            if(this->pages.at(page).rows.find(row+i)==this->pages.at(page).rows.end())
            {
                string newRow(rowLength,'_');
                this->pages.at(page).rows.insert({row+i,newRow});
                this->pages.at(page).numOfRows = this->pages.at(page).rows.size();
            }
            string tmp(1,str.at(i));
            p.rows.at(row+i).replace(column,1,tmp);
        }
    }
}

string Notebook::read(unsigned int page, unsigned int row, unsigned int column, ariel::Direction direction, unsigned int length)
{
    string final;
    Page& p = this->pages.at(page);
    if(direction==Direction::Horizontal)
    {
        final += p.rows.at(row).substr(column, length);   
    }
    else
    {
        for (unsigned int i = 0; i < length; i++)
        {
            // row does not exist
            if(p.rows.find(row+i)==p.rows.end())
            {
                //string newRow(rowLength,'_');
                final += '_';
                // p.rows.insert({row+i,newRow});
                // p.numOfRows = p.rows.size();
            }
            else
            {
                final += p.rows.at(row+i).at(column);
            }
        }
    }
    return final;
}

void Notebook::erase(unsigned int page, unsigned int row, unsigned int column, ariel::Direction direction, unsigned int length)
{
    Page& p = this->pages.at(page);
    string str(length,'~');
    if(direction==Direction::Horizontal)
    {
        p.rows.at(row).replace(column,length, str);
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

void Notebook::show(unsigned int index)
{
    // find the min and max row
    Page& p = this->pages.at(index);
    unsigned int maxPage = 0;
    unsigned int minPage = UINT32_MAX;
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
    string final;
    for (unsigned int i = minPage; i < maxPage + 1; i++)
    {
        // row does not exist or empty page
        if(this->pages.at(index).rows.find(i)==this->pages.at(index).rows.end())
        {
            string newRow(rowLength,'_');
            final += std::to_string(i) + "\t: " + newRow + "\n";
        }
        else
        {
            final += std::to_string(i) + "\t: " + this->pages.at(index).rows.at(i) + "\n";
        }
    }
    if(!final.empty())
    {
        final.pop_back();
    }
    cout << final << endl;
}