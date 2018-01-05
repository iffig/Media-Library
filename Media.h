#ifndef MEDIA_H
#define MEDIA_H
#include <string>

class Media{
    public:
        Media();
        Media(std::string* details);
        virtual ~Media();

        std::string title;
        std::string genre;
        std::string year;
        std::string rating;
        bool isFavorite;

        void addFavorite();

        // Abstract classes to be filled in

        virtual void use() = 0;
        virtual void printDetails() = 0;
        virtual Media* add() = 0;
        virtual void update() = 0;

    protected:
    private:

};

#endif // MEDIA_H
