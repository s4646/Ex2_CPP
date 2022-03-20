#pragma once
#include <unordered_map>
#include <string>

namespace ariel
{
    class Page
    {
        private:
            unsigned int numOfRows;
            unsigned int maxRowLength;
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
            void write(unsigned int page, unsigned int row, unsigned int column, ariel::Direction direction, std::string str);
            std::string read(unsigned int page, unsigned int row, unsigned int column, ariel::Direction direction, unsigned int length);
            void erase(unsigned int page, unsigned int row, unsigned int column, ariel::Direction direction, unsigned int length);
            void show(unsigned int index);
    };
}