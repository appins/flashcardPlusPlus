#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

// Interpret line values
unsigned char inter(string line, int lineNum) {

  // Flags
  constexpr unsigned char correctFormat { 0x01 };
  constexpr unsigned char correctAnswer { 0x02 };
  constexpr unsigned char isQuestion    { 0x04 };

  unsigned char result{ 0x00 };
  result |= correctFormat;

  // Make sure the first line of the file is correct
  if(lineNum == 0 && line != "Flashcard++, by App1ns") {
    cout << "File error, first line was incorrect!";
    result &= ~correctFormat;
  }

  //                              Normal question

  else if(line[0] == 'Q' && line[1] == ' ') {
    // Flag as question
    result |= isQuestion;

    cout << "Question" << endl;

    // Clear cin if failed
    if(cin.fail()){
      cin.clear();
      cin.ignore(10000, '\n');
    }

    // Split string by comma (everything after "Q ")
    stringstream flashcard{ line.substr(2, line.size()) };
    string question;
    string answer;
    getline(flashcard, question, ',');
    getline(flashcard, answer  , ',');

    // Ask the question then get the answer
    cout << '\t' << question << endl << '\t';

    string userAnswer;
    getline(cin, userAnswer);

    string displayAnswer{ answer };

    // All uppercase for if statement bellow
    std::transform(answer.begin(), answer.end(),answer.begin(), ::toupper);
    std::transform(userAnswer.begin(), userAnswer.end(),userAnswer.begin(), ::toupper);

    if(userAnswer == answer) {
      cout << "Good job!" << endl << endl;
      result |= correctAnswer;
    }
    else {
      cout << "Ugh oh, the real answer was " << displayAnswer << endl << endl;
    }
  }

  //                              Multiple choice question

  else if(line[0] == 'M' && line[1] == ' '){
    // Flag as question
    result |= isQuestion;

    cout << "Multiple choice" << endl;

    // Clear cin if failed
    if(cin.fail()){
      cin.clear();
      cin.ignore(10000, '\n');
    }

    // 3 Way split of string
    stringstream flashcard{ line.substr(2, line.size()) };
    string question;
    string choices;
    string answer;
    getline(flashcard, question, '&');
    getline(flashcard, choices,  '&');
    getline(flashcard, answer,   '&');

    // Ask question
    cout << '\t' << question << endl;

    // Display choices
    stringstream choicess{ choices };
    string currentChoice;
    while(getline(choicess, currentChoice, ',')){
      cout << "\t\t" << currentChoice << endl;
    }

    // Get user answer
    cout << "Answer: ";
    string userAnswer;
    cin >> userAnswer;

    string displayAnswer{ answer };

    // All uppercase for if statement bellow
    std::transform(answer.begin(), answer.end(),answer.begin(), ::toupper);
    std::transform(userAnswer.begin(), userAnswer.end(),userAnswer.begin(), ::toupper);

    if(answer == userAnswer){
      cout << "Good job!" << endl;
      result |= correctAnswer;
    }
    else{
      cout << "Ugh oh! The actuall answer was " << displayAnswer << endl;
    }

    cin.clear();
    cin.ignore(10000, '\n');

  }

  //                              True / false question (That is true)
  else if(line[0] == 'T' && line[1] == ' '){
    // Flag
    result |= isQuestion;

    cout << "True or false" << endl;

    // Get question
    stringstream liness{ line.substr(2, line.size()) };
    string question;
    getline(liness, question);
    cout << '\t' << question;

    // Ask for answer
    cout << endl << "Answer: ";
    string ans;
    getline(cin, ans);

    char ansChar = toupper(ans[0]);

    if(ansChar == '1' || ansChar == 'T' || ansChar == 'Y'){
      cout << "Good job!" << endl << endl;
      result |= correctAnswer;
    }
    else{
      cout << "The real answer was true" << endl;
    }
  }

  //                              True / false question (That is false)
  else if(line[0] == 'F' && line[1] == ' '){
    // Flag
    result |= isQuestion;

    cout << "True or false" << endl;

    // Get question
    stringstream liness{ line.substr(2, line.size()) };
    string question;
    getline(liness, question);
    cout << '\t' << question;

    // Ask for answer
    cout << endl << "Answer: ";
    string ans;
    getline(cin, ans);

    char ansChar = toupper(ans[0]);

    if(ansChar == '0' || ansChar == 'F' || ansChar == 'N'){
      cout << "Good job!" << endl << endl;
      result |= correctAnswer;
    }
    else{
      cout << "The real answer was false" << endl;
    }
  }
  return result;
}
