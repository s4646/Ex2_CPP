#pragma once
#include <unordered_map>
#include <string>
#include "Direction.hpp"

namespace ariel
{
    const unsigned int rowLength = 100;
    class Page
    {
        private:
            unsigned int numOfRows;
            std::unordered_map<unsigned int,std::string> rows;

        public:
            Page();
            
            friend class Notebook;
    };

    class Notebook
    {
        private:
            unsigned int numOfPages;
            std::unordered_map<unsigned int,Page> pages;

        public:
            Notebook();
            void write(unsigned int page, unsigned int row, unsigned int column, Direction direction, const std::string& str);
            std::string read(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length);
            void erase(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length);
            void show(unsigned int index);
    };
}