/* Library.h and Library.cpp are used to manage the
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

  Media* item = new Media();

  while (getline (fileName, line)){
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
  cout << "Library Built" << endl;
}

void Library::addMedia(Media *newItem){
  LibNode *temp = new LibNode(newItem);

  temp->item = newItem;
  temp->parent = NULL;
  temp->leftChild = NULL;
  temp->rightChild = NULL;

  if(root == NULL){
    root = temp;
    cout << "inserting at root " << root->item->title<< endl;
  }

}

void Library::printLibrary(){
  cout << "root is " << root->item->title << endl;
  printLibrary(root);
}

void Library::printLibrary(LibNode *node){
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
