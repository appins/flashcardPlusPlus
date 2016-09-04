#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include "fcard.hpp"

typedef unsigned short version_t ;

using namespace std;

int main(int argc, char *argv[]) {
  // Seed random numbers for flash card order
  srand(time(NULL));

  // Serialized version, write this to file
  version_t version{ 1 };

  // Open the flashcard set (should be named "set.flashcard")
  // Unless command line argument says otherwise
  ifstream flashcards;
  if(argc == 1) {
    flashcards.open("flashcard.set");
  }
  else {
    flashcards.open(argv[1]);
  }

  // If file exists, read from it
  if( flashcards.is_open() ) {
    string line;

    // For each line, pass it to the function inter
    getline(flashcards, line);
    inter(line, 0);

    string versionOnSet;
    getline(flashcards, versionOnSet);

    vector<string> lines;
    while( getline(flashcards, line)) {
      lines.push_back(line);
    }

    // Flags
    constexpr unsigned char correctFormat { 0x01 };
    constexpr unsigned char correctAnswer { 0x02 };
    constexpr unsigned char isQuestion    { 0x04 };

    int correct{ 0 };
    int outOf{ static_cast<int>(lines.size()) + 1 };

    if( !lines.size() ){
      cout << "No information in flashcard set" << endl;
      exit(0);
    }

    for(int i{ 0 }; i <= static_cast<int>(lines.size()); i++){
      unsigned char lineAnswer{ inter(lines[rand() % lines.size()], 1) };
      if(lineAnswer & correctAnswer){
        correct++;
      }
      if( ! (lineAnswer & isQuestion) ){
        outOf--;
      }
      if( ! (lineAnswer & correctFormat) ){
        cout << "Error";
        break;
      }
    }

    cout << endl << endl << correct << " out of " << outOf << " correct";

  }

  // Otherwise create the file
  else {
    ofstream flashcards{ "flashcard.set" };
    flashcards << "Flashcard++, by App1ns" << endl;
    flashcards << "v" << version;
    flashcards << endl;

    cout << "Created \"flashcard.set\"" << endl;
    cout << "Please restart the program" << endl;
    flashcards.close();
  }

  flashcards.close();

  // Wait for user input and end program
  cout << endl << endl << "Hit enter to continue...";
  cin.get();

  return 0;
}
