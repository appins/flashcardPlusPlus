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
    make unix
```

## Writing flashcards:

  Currently there are normal questions and multiple choice questions

  * Normal Questions

    Syntax: `Q question,answer`

    * Normal questions should always start with "Q"
    * Question and answer should be separated with a comma

    Example: `Q what's the square root of 100?,10`

  * Multiple Choice

    Syntax: `M question&choice1,choice2&answer`

      * Each part (question, choices, and answer) should have a '&' separating it
      * Each choice should have a comma separating it
      * Make sure to put the title of the choice before the choice, like "A: 10"

      Example: `M Which number is prime?&A: 4,B: 15, C: 21, D: 17&D`


## Using the writer:

  Instead of writing flashcards by yourself, just fire up the writer and get going.

  To get the writer fired up, rev up a terminal and type
  ```sh
    git clone git@github.com:AppIns/flashcardPlusPlus.git
    cd flashcardPlusPlus
    cd writer
    make unix
  ```
  On windows, replace the last line with `make win`

  The writer should come with instructions on how to use it


Need help? Found a bug? Email AlexAndersonOne@gmail.com with details!
