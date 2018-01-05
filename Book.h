#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Media.h"

class Book: public Media{
    public:
        Book();
        Book(std::string* details);
        virtual ~Book();

        std::string author;
        std::string publisher;
        std::string pages;
        int readCount;

        void use();
        Media* add();
        void update();
        void printDetails();

    protected:
    private:

};

#endif // BOOK_H
