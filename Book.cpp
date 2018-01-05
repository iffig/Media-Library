#include "Book.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Book::Book() : Media(){
}

Book::Book(string* details) : Media(details){
  author = details[5];
  publisher = details[6];
  pages = details[7];
  readCount = 0;
}

Book::~Book(){
}

void Book::use(){
  readCount++;
}
Media* Book::add(){

  string title, genre, year, rating, author, publisher, pages;

  cout << "=== Add Book ===" << endl;

  cout << "Enter title: ";
  getline(cin, title);
  cout << "Enter author: ";
  getline(cin, author);
  cout << "Enter genre: ";
  getline(cin, genre);
  cout << "Enter publisher: ";
  getline(cin, publisher);
  cout << "Enter year: ";
  getline(cin, year);
  cout << "Enter number of pages: ";
  getline(cin, pages);
  cout << "Enter rating: ";
  getline(cin, rating);

  string details[8] = {"", title, genre, year, rating, author, publisher, pages};

  Book* book = new Book(details);
  return book;
}

void Book::update(){
  readCount++;
}

void Book::printDetails(){
  cout << "=== Media Details ===" << endl;
  cout << "Title: " << title << endl;
  cout << "Author: " << author << endl;
  cout << "Genre: " << genre << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Year:" << year << endl;
  cout << "Pages:" << pages << endl;
  cout << "Rating: " << rating << endl;
  cout << "Times Read: " << to_string(readCount) << endl << endl;
}
