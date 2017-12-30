#ifndef MEDIA_H
#define MEDIA_H
#include <string>

class Media
{
    public:
        Media();
        virtual ~Media();

        std::string title;
        std::string genre;
        std::string year;

        void setDetails(std::string title, std::string genre, std::string year, std::string rating);
        void printDetails();
        std::string getRating();
        void updateDetails(std::string attribute);
    protected:
    private:
      std::string rating;
};

#endif // MEDIA_H
