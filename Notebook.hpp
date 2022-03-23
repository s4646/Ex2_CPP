#pragma once
#include <unordered_map>
#include <string>
#include "Direction.hpp"

namespace ariel
{
    const int rowLength = 100;
    class Page
    {
        private:
            int numOfRows;
            std::unordered_map<int,std::string> rows;

        public:
            Page();
            
            friend class Notebook;
    };

    class Notebook
    {
        private:
            int numOfPages;
            std::unordered_map<int,Page> pages;

        public:
            Notebook();
            void write(int page, int row, int column, Direction direction, const std::string& str);
            std::string read(int page, int row, int column, Direction direction, int length);
            void erase(int page, int row, int column, Direction direction, int length);
            void show(int index);
    };
}