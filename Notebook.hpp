
#pragma once
#include <vector>
#include <string>

namespace ariel
{
    class Page
    {
        private:
            int numOfRows;
            std::vector<std::string> rows;

        public:
            std::string getRow();
            void editRow();
    };

    class Notebook
    {
        private:
            int numOfPages;
            std::vector<Page> pages;

        public:
            /* ***** */
            void write(int page, int row, int column, ariel::Direction direction, std::string str);
            std::string read(int page, int row, int column, ariel::Direction direction, int length);
            void erase(int page, int row, int column, ariel::Direction direction, int length);
            void show(int page);
            /* ***** */
    };
}