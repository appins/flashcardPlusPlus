#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

typedef unsigned short version_t;

int main(){
  // Serialized version number
  version_t version{ 5 };

  // Input and output file stream
  ifstream flashcardset{ "flashcard.set" };
  ofstream writefcardset;

  // Check if ifstream exists
  if(flashcardset.is_open()){
    cout << "Found flashcard.set" << endl;

    flashcardset.close();
  }

  // If not, create it
  else{

    cout << "Creating flashcard.set..." << endl;

    ofstream flashcards{ "flashcard.set" };
    flashcards << "Flashcard++, by App1ns" << endl;
    flashcards << "v" << version;
    flashcards << endl;

    cout << "Done, please restart the program..." << endl;

    flashcards.close();

    exit(0);
  }

  // Open it (in append mode)
  writefcardset.open("flashcard.set", fstream::app);

  bool userQuit{ false };

  while( !userQuit ){
    // Get user input
    cout << endl << "Writing a flashcard";
    cout << endl << "(M)ultiple Choice, (Q)uestion, (T)rue/False, or 'Quit': ";
    string userInput;
    cin >> userInput;

    // User input to uppercase
    std::transform(userInput.begin(), userInput.end(),userInput.begin(), ::toupper);

    // If user decided to quit
    if(userInput == "QUIT" || userInput == "'QUIT'"){
      userQuit = true;
    }

    // If user chose multiple choice
    else if(userInput == "M" || userInput == "MULTIPLE" ||
      userInput == "MULTIPLE CHOICE" || userInput == "(M)ultiple Choice"){
        string multichoice{ "SM " };

        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Question: ";
        string question;
        getline(cin, question);

        multichoice += question + "&";

        cout << "Enter '.' to stop inputting wrong answers" << endl;

        // Vector of strings for answers
        std::vector<string> answers;

        char i{ 0 };
        string pAns;

        // Get possible answers
        do{
          i++;

          cout << "Wrong answer: ";

          getline(cin, pAns);

          // Push back into vector
          answers.push_back(pAns);
      }while(pAns != "." && i < 26);

        // Make sure vector ends with a '.'
        answers.push_back(".");

        // For every item in answers (Without a '.'), append it to multichoice
        for(string i: answers){
          if(i[0] != '.'){
            multichoice += i + ",";
          }
          else{
            break;
          }
        }

        // Trim off the extra ',' and add another '&' for the answer
        multichoice = multichoice.substr(0, multichoice.size() - 1 );
        multichoice += "&";

        // Get the real answer
        cout << "What is the real answer? ";
        string answer;
        getline(cin, answer);
        multichoice += answer;

        // Write to file
        writefcardset << multichoice << endl;

        cout << "Written to file";

    }

    // If user chose a normal question type
    else if(userInput == "Q" || userInput == "QUESTION" ||
      userInput == "(Q)uestion"){
        string flashQuestion{ "Q " };

        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Question: ";
        string question;
        getline(cin, question);

        flashQuestion += question;
        flashQuestion += ",";

        cout << "Answer: ";
        string answer;
        getline(cin, answer);

        flashQuestion += answer;

        writefcardset << flashQuestion << endl;

        cout << "Written to file" << endl;

      }
    // True or false question
    else if(userInput[0] == 'T'){

      cout << "True or false flashcard" << endl;

      cin.clear();
      cin.ignore(10000, '\n');

      cout << "Question: ";
      string oQuestion;
      getline(cin, oQuestion);

      cout << "Press enter to continute...";

      cin.clear();
      cin.ignore(10000, '\n');

      string answer;
      bool answerIsValid{ false };
      bool answerType;

      cout << "Answer: ";
      do{
        getline(cin, answer);
        if(toupper(answer[0]) == 'F' || toupper(answer[0]) == '0' || toupper(answer[0]) == 'N'){
          answerIsValid = true;
          answerType = false;
        }
        else if(toupper(answer[0]) == 'T' || toupper(answer[0]) == '1' || toupper(answer[0]) == 'Y'){
          answerIsValid = true;
          answerType = true;
        }
        else{
          answerIsValid = false;
          cout << "Answer: ";
        }
      }
      while( !answerIsValid );

      string flashcardS = (answerType) ? "T " : "F ";

      flashcardS += oQuestion;

      writefcardset << flashcardS << endl;

      cout << "Written to file";
    }
  }

  writefcardset.close();

  return 0;
}
