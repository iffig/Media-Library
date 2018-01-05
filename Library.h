#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include "Media.h"
#include "Book.h"
#include "Movie.h"

struct LibNode{
    Media* item;
    LibNode* parent;
    LibNode* leftChild;
    LibNode* rightChild;

    LibNode(){}
    LibNode(Media* media_item){
      item = media_item;
    }
};

class Library
{
    public:
        Library();
        virtual ~Library();
        void buildLibrary(std::string file);
        void addMedia(Media* item);
        void deleteMedia(std::string title);
        Media* createItem();
        void setRoot(LibNode* node);
        LibNode* getRoot();
        void printLibrary();
        void searchLibrary();
        LibNode* findItem(LibNode* node, std::string searchString);
    protected:
    private:
      LibNode* root;
      void printLibrary(LibNode* node);
};

#endif // LIBRARY_H
