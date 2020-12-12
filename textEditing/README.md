# Author Details

Author Name: Desmond Gilmour

Author Email: desmondgilmour@gmail.com

***
## Program Description
The program is meant to take input from the terminal as a string and apply different operations to the text to simplify and remove various characters. The performance structure is updated each time more input is added. The motivation behind this project was to update an old project from first year using some knowledge that I have obtained in my second year.

***
## How to Run 
#### Running From the Terminal
1. Type `make` on the terminal to create all required files
2. The `./findWords` on the terminal to execute the program 
3. Enter input through the terminal and press enter or return to submit
4. End the program by typing 'N' when the program prompts the user to enter 'N'

#### Running From the Bash Script Provided
1. If you do not have access to the Bash script use `chmod 755 textEditingBash.sh` to change permissions
2. `./textEditingBash.sh` will run the bash script to input one line of input

***
## Files included
| File Name | File Purpose |
|-----------|--------------|
|findWords.c|Contains the main and prints all required user input|
|textEditing.c|Contains all functions made that apply to this program|
|textProc.h| the library file which includes stdlib.h, stdio.h, string.h as well as the structure definition for performance|
|textEditingBash.sh|A bash script that has premade input that that one can use instead|

***
## Function Names
| Function Name | Function Arguement | Function Purpose |
|---------------|--------------------|------------------|
|`applyAllTextOps()`|char *line, struct Performance *performance|Applies the 6 functions outlined below to the string|
|`printStats()`|struct Performance *performance|Prints the record of each operation|
|`newPerformance()`|N/A|Mallocs space for a performance struct to be created and returns it|
|`chop()`|char *line|'Remove the newline character from a input string and returns the total newline characters removed|
|`convertLowerCase()`|char *line|Converts all uppercase characters to lowercase and returns the total operations performed|
|`reduceSpace()`|char *line|Removes all extra blank space and tab characters and replaces them with a single blank space and returns the amount of character removed|
|`replaceDigits()`|char *line|Replaces all digits with a blank space and returns the total of removed digits|
|`replacePunc()`|char *line|Replaces all punctuation with blank spaces and returns the total of removed punctuation|
|`trim()`|char *line|Removes all leading and trailing blank space and returns the total blank space removed|
