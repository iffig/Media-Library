#include "Media.h"
#include <iostream>
#include <cstdlib>

using namespace std;
// Initialize with default information
Media::Media(){
  title = "N/A";
  genre = "N/A";
  year = "N/A";
  rating = "N/A";
}

Media::~Media(){
}

void Media::setDetails(string _title, string _genre, string _year, string _rating){
  title = _title;
  genre = _genre;
  year = _year;
  rating = _rating;
}

void Media::printDetails(){

  cout << "=== Media Details ===" << endl;
  cout << "Title: " << title << endl;
  cout << "Genre: " << genre << endl;
  cout << "Year:" << year << endl;
  cout << "Rating: " << rating << endl << endl;

}

string Media::getRating(){
  return rating;
}

void Media::updateDetails(string attribute){

}
