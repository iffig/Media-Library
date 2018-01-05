#include "Movie.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Movie::Movie() : Media(){
}

Movie::Movie(string* details) : Media(details){
  summary = details[5];
  duration = details[6];
  director = details[7];
  watchCount = 0;
}

Movie::~Movie(){
}

void Movie::use(){
  watchCount++;
}

Media* Movie::add(){

  string title, genre, year, rating, summary, duration, director;

  cout << "=== Add Movie ===" << endl;

  cout << "Enter title: ";
  getline(cin, title);
  cout << "Enter director: ";
  getline(cin, director);
  cout << "Enter genre: ";
  getline(cin, genre);
  cout << "Enter year: ";
  getline(cin, year);
  cout << "Enter duration: ";
  getline(cin, duration);
  cout << "Enter rating: ";
  getline(cin, rating);
  cout << "Enter summary: ";
  getline(cin, summary);

  string details[8] = {"", title, genre, year, rating, summary, duration, director};

  Movie* movie = new Movie(details);
  return movie;
}

void Movie::update(){
  watchCount++;
}

void Movie::printDetails(){
  cout << "=== Media Details ===" << endl;
  cout << "Title: " << title << endl;
  cout << "Director: " << director << endl;
  cout << "Year: " << year << endl;
  cout << "Duration:" << duration << endl;
  cout << "Summary:" << summary << endl;
  cout << "Rating: " << rating << endl;
  cout << "Times Watched: " << to_string(watchCount) << endl << endl;
}
