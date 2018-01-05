#include "Media.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Media::Media(){
}

Media::Media(string* details){
  title = details[1];
  genre = details[2];
  year = details[3];
  rating = details[4];
  isFavorite = false;
}

Media::~Media(){
}

void Media::addFavorite(){

}
