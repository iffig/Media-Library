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
      string details[10];
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
      if(details[0] == "book"){
        Book* item = new Book(details);
        addMedia(item);
      }
  }
  //Close File
  fileName.close();
  cout << "Library Successfully Built" << endl << endl;
}

void Library::setRoot(LibNode* node){
  root = node;
}

LibNode* Library::getRoot(){
  return root;
}

// This is the only function that will change if using a non-media item
Media* Library::createItem(){
  string type;
  cout << "What type of media are you adding? book | movie | album " << endl;;
  getline(cin, type);

  if(type == "book"){
    Book* book = new Book();
    return book->add();
  }
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
  if (getRoot() == NULL){
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
  if(root == NULL)
    cout << "Your Library is empty." << endl;
  else
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
  searchNode = findItem(root, searchString);
  cout << endl;
  if(searchNode == NULL){
    cout << "Item not found." << endl << endl;
  }
  else{
    searchNode->item->printDetails();
  }
}

LibNode* Library::findItem(LibNode* searchNode, string searchString){
  if (searchNode == NULL || searchNode->item->title == searchString){
      return searchNode;
  }
  else{
    if(searchString < searchNode->item->title)
        searchNode = findItem(searchNode->leftChild, searchString);
    else
        searchNode = findItem(searchNode->rightChild, searchString);
    return searchNode;
  }
}

void Library::deleteMedia(string title){

  LibNode* itemNode = new LibNode();
  // Find item to delete
  itemNode = findItem(root, title);

  if(itemNode == NULL){
    cout << "Item not in library." << endl;
  }
  else if(itemNode != NULL){
    // Item node has no children
    if(itemNode->rightChild == NULL && itemNode->leftChild == NULL){
      if(itemNode == getRoot())
        setRoot(NULL);
      else if(itemNode == itemNode->parent->leftChild)
        itemNode->parent->leftChild = NULL;

      else if (itemNode == itemNode->parent->rightChild)
        itemNode->parent->rightChild = NULL;

      delete itemNode;
      itemNode = NULL;
      return;
    }

    // Item node has one child

    // Item node has right child
    else if(itemNode->leftChild == NULL && itemNode->rightChild != NULL){
      if(itemNode == getRoot())
        setRoot(itemNode->rightChild);
      else if(itemNode == itemNode->parent->leftChild)
        itemNode->parent->leftChild = itemNode->rightChild;

      else if (itemNode == itemNode->parent->rightChild)
        itemNode->parent->rightChild = itemNode->rightChild;

      delete itemNode;
      itemNode = NULL;
      return;
    }

    // Item node has left child
    else if (itemNode->rightChild == NULL && itemNode->leftChild != NULL) {
      if(itemNode == getRoot())
        setRoot(itemNode->leftChild);

      else if(itemNode == itemNode->parent->leftChild)
        itemNode->parent->leftChild = itemNode->leftChild;

      else if (itemNode == itemNode->parent->rightChild)
        itemNode->parent->rightChild = itemNode->leftChild;

      delete itemNode;
      itemNode = NULL;
      return;
    }

    // Item node has two children
    else{
      if(itemNode->rightChild->leftChild!=NULL){
        LibNode* currLeft;
        LibNode* currLeftParent;
        currLeftParent=itemNode->rightChild;
        currLeft=itemNode->rightChild->leftChild;
        while(currLeft->leftChild != NULL){
          currLeftParent=currLeft;
          currLeft=currLeft->leftChild;
        }
        itemNode->item->title=currLeft->item->title;
        delete currLeft;
        currLeft = NULL;
        currLeftParent->leftChild= NULL;
      }
      else {
        LibNode* temp =itemNode->rightChild;
        itemNode->item->title=temp->item->title;
        itemNode->rightChild=temp->rightChild;
        delete temp;
        temp = NULL;
      }
    }
    }
}
