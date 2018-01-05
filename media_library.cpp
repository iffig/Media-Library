//This is the Driver program for the media library
#include <iostream>
#include <fstream>
#include "Library.h"
using namespace std;

void userMenu();

int main(int argc, char* argv[]){

  Library* my_library = new Library();

  cout << endl << "Will build library from: " << argv[1] << endl << endl;
  my_library->buildLibrary(argv[1]);

  // CLI Options
  string selection;

  while(selection != "q")
  {
      userMenu();
      getline(cin, selection);
      // View media
      if(selection=="1"){
        //Prints all
        my_library->printLibrary();
      }
      // View favorites
      else if(selection=="2"){
        // Print only favorites
      }
      // Search media library
      else if(selection=="3"){
        my_library->searchLibrary();
      }
      // Rate items
      else if(selection=="4"){

      }
      // Mark item use
      else if(selection == "5"){
      }
      // Add item to library
      else if(selection == "6"){
        my_library->addMedia(my_library->createItem());
      }
      // Remove item from library
      else if(selection == "7"){
        string title;
        cout << "Enter title to delete: ";
        getline(cin, title);
        my_library->deleteMedia(title);
      }
      else if(selection == "root"){
        LibNode* r = my_library->getRoot();
        cout << r->item->title << endl;
      }
  }
}

void userMenu(){
    //Prints out Main Menu
    cout << "====== My Media Library =====" << endl;
    cout << "1. View media" << endl;
    cout << "2. View favorites" << endl;
    cout << "3. Search media library" << endl;
    cout << "4. Rate item" << endl;
    cout << "5. Mark item use" << endl;
    cout << "6. Add item to library" << endl;
    cout << "7. Remove item from library" << endl;

    cout << "Press 'q' to quit" << endl;
}
