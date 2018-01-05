#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "Media.h"

class Movie: public Media{
    public:
        Movie();
        Movie(std::string* details);
        virtual ~Movie();

        std::string summary;
        std::string duration;
        std::string director;

        int watchCount;

        void use();
        Media* add();
        void update();
        void printDetails();

    protected:
    private:

};

#endif // MOVIE_H
