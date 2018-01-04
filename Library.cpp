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

void Library::setRoot(LibNode *node){
  root = node;
}

void Library::addMedia(Media *newItem){

    // Create the node we will be inserting
    LibNode * temp = new LibNode(newItem);
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    temp->parent = NULL;

    LibNode * x = root;
    LibNode * y = NULL;

    // Do we have an empty tree?
    if (root == NULL){
      setRoot(temp);
    }
    // If the tree is not empty
    else
    {
        // Get to the end of the tree, where we need to add this node.
        while (x != NULL)
        {
            y = x;
            if(temp->item->title.compare(x->item->title) < 0)
                x = x->leftChild;
            else
                x = x->rightChild;

        }
        // set the parent of this node to be the previous node.
        temp->parent = y;

        // Determine which child to this previous node we are at.
        if (temp->item->title.compare(y->item->title) < 0)
            y->leftChild = temp;
        else
            y->rightChild = temp;
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
