/*
   Library.h and Library.cpp are used to manage the
   actions of the underlying BST that is storing
   the contents of the media library.
*/

#include "Library.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

Library::Library(){
  root = NULL;
}

Library::~Library(){
}

void Library::buildLibrary(string file){
  //Open File
  fstream fileName;
  fileName.open(file);
  string line;


  while (getline (fileName, line)){
      Media* item = new Media();
      string details[4];
      int i = 0;
      while(!line.empty()){
        int delimiter = line.find(',');
        // Word at end of line
        if(delimiter == -1){
          delimiter = line.length();
          details[i] = line.substr(0, delimiter);
          line = "";
        }
        else{
          details[i] = line.substr(0, delimiter);
          line = line.substr(delimiter+2, line.length());
        }
        i++;
      }
      item->setDetails(details[0], details[1], details[2], details[3]);
      addMedia(item);
  }
  //Close File
  fileName.close();
  cout << "Library Successfully Built" << endl << endl;
}

void Library::setRoot(LibNode* node){
  root = node;
}

Media* Library::getRoot(LibNode* node){
  root = node;
}

Media* Library::createItem(){
  string title, genre, year, rating;

  cout << "=== Add Media Item ===" << endl;
  cout << "Enter title: ";
  getline(cin, title);

  cout << "Enter genre: ";
  getline(cin, genre);

  cout << "Enter year: ";
  getline(cin, year);

  cout << "Enter rating: ";
  getline(cin, rating);

  Media* item = new Media();
  item->setDetails(title, genre, year, rating);

  return item;
}

void Library::addMedia(Media* newItem){

    // Create the node we will be inserting
    LibNode * temp = new LibNode(newItem);
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    temp->parent = NULL;

    LibNode * x = root;
    LibNode * y = NULL;

    // If tree is empty
    if (root == NULL){
      setRoot(temp);
    }
    else{
        // Find where to insert node
        while (x != NULL){
            y = x;
            if(temp->item->title.compare(x->item->title) < 0)
                x = x->leftChild;
            else
                x = x->rightChild;

        }
        // Set inserted node's parent
        temp->parent = y;

        // Set inserted node as correct child of parent
        if (temp->item->title.compare(y->item->title) < 0)
            y->leftChild = temp;
        else
            y->rightChild = temp;
    }
}

void Library::printLibrary(){
  cout << endl << "=== Your Media Library ===" << endl;
  printLibrary(root);
  cout << endl;
}

void Library::printLibrary(LibNode* node){
  LibNode* current = new LibNode();
  current = node;

  if(current->leftChild != NULL){
      printLibrary(current->leftChild);
  }
  cout << "Title: " << current->item->title << endl;

  if(current->rightChild != NULL){
      printLibrary(current->rightChild);
  }
}

//Currently for search by title
void Library::searchLibrary(){
  string searchString;
  LibNode* searchNode = new LibNode();

  cout << endl << "=== Media Search ===" << endl;
  cout << "Enter Title: ";
  getline(cin, searchString);
  searchNode = searchLibrary(root, searchString);
  cout << endl;
  if(searchNode == NULL){
    cout << "Item not found." << endl << endl;
  }
  else{
    searchNode->item->printDetails();
  }
}

LibNode* Library::searchLibrary(LibNode* searchNode, string searchString){
  if (searchNode == NULL || searchNode->item->title == searchString){
      return searchNode;
  }
  else{
    if(searchString < searchNode->item->title){
        searchNode = searchLibrary(searchNode->leftChild, searchString);
    }
    else{
        searchNode = searchLibrary(searchNode->rightChild, searchString);
    }
    return searchNode;
  }
}
