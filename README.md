# flashcard++
#### A simple flashcard program written in C++

To get started fire up a terminal and type
```sh
    git clone git@github.com:AppIns/flashcardPlusPlus.git
    cd flashcardPlusPlus
    make unix
```
Or on windows systems, fire up a CMD and type
```sh
    git clone git@github.com:AppIns/flashcardPlusPlus.git
    cd flashcardPlusPlus
    make win
```

## Writing flashcards:

  Currently there are normal questions and multiple choice questions

  * Normal Questions

    Syntax: `Q question,answer`

    * Normal questions should always start with "Q"
    * Question and answer should be separated with a comma
    * Case insensitive

    Example: `Q what's the square root of 100?,10`

  * Multiple Choice

    Syntax: `M question&choice1,choice2&answer`

      * Each part (question, choices, and answer) should have a '&' separating it
      * Each choice should have a comma separating it
      * Make sure to put the title of the choice before the choice, like "A: 10"
      * Case insensitive

      Example: `M Which number is prime?&A: 4,B: 15, C: 21, D: 17&D`

  * True / False questions

      Syntax `T question` or `F question`

      * Smart detection (Yes, No, True, False, 1, 0, t, f, y, n, Yeah, Nope)
      * Start questions that are true with 'T' and false with 'F'
      * Case insensitive

      Examples: `T Is C++ better than Java?`
                `F Is the square root of n always n/10?`


## Using the writer:

  Instead of writing flashcards by hand, just fire up the writer and get going.

  To get the writer fired up, rev up a terminal and type
  ```sh
    git clone git@github.com:AppIns/flashcardPlusPlus.git
    cd flashcardPlusPlus
    cd writer
    make unix
  ```
  On windows, replace the last line with `make win`

  The writer should come with instructions on how to use it.

## Opening custom flashcard files
  All Flashcard++ files must begin with "Flashcard++, by App1ns"
  To open custom files, pass their relative paths though the command line

  There is even a special makefile target for this

  `make build` and `make build_win` compile the program but don't run it

  Currently there is no such support with the writer, I will do that soon though

Need help? Found a bug? Email AlexAndersonOne@gmail.com with details!
