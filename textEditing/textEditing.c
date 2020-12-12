#include "textProc.h"

int chop(char *line);
int convertLowerCase(char *line);
int replaceDigits(char *line);
int replacePunc(char *line);
int reduceSpace(char *line);
int trim(char *line);

/* applyAllTextOps implements all text operations on the given string
*
* line (char): the string to perform the operation
* performance (Struct Performance): tracks all changes 
*/
void applyAllTextOps(char *line, struct Performance *performance)
{
    performance->chopNum += chop(line);
    performance->lowerCaseNum += convertLowerCase(line);
    performance->replaceDigitsNum += replaceDigits(line);
    performance->replacePuncNum += replacePunc(line);
    performance->reduceSpaceNum += reduceSpace(line);
    performance->trimNum += trim(line);
}

/* printStats reports the changes that have been made to the text and then frees the 
*
* performance (Struct Performance): tracks all changes 
*/
void printStats(struct Performance *performance)
{
    printf("The following changes have been made to the input entered.\n");
    printf("Newline characters removed: %d\n"
            "Uppercase letters replaced: %d\n"
            "Blank space removed: %d\n"
            "Number removed: %d\n"
            "Punctuation removed: %d\n"
            "Leading and trailing spaces removed: %d\n",
            performance->chopNum, performance->lowerCaseNum,
            performance->reduceSpaceNum, performance->replaceDigitsNum,
            performance->replacePuncNum, performance->trimNum);
}

struct Performance *newPerformance()
{
    struct Performance *performanceToReturn = malloc(sizeof(struct Performance));

    if (performanceToReturn == NULL)
    {
        fprintf(stderr, "Fatal: failed to allocate memory towards the performance struct.\n");
        exit(0);
    }


    performanceToReturn->chopNum = 0;
    performanceToReturn->lowerCaseNum = 0;
    performanceToReturn->reduceSpaceNum = 0;
    performanceToReturn->replaceDigitsNum = 0;
    performanceToReturn->replacePuncNum = 0;
    performanceToReturn->trimNum = 0;

    return performanceToReturn;
}

/* chop removes all new line characters that exists within a given text
*
* line (char): the string to perform the operation
*/
int chop(char *line)
{
    int totalReplaced = 0;
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == '\n' || line[i] == '\r')
        {
            line[i] = '\0';
            totalReplaced++;
        }
    }
    return totalReplaced;
}

/* convertLowerCase coverts all uppercase letters to lowercase
*
* line (char): the string to perform the operation
*/
int convertLowerCase(char *line)
{
    int character;
    int i;
    int total = 0;

    int lineLength = strlen(line);
    for (i = 0; i < lineLength; i++)
    {
        character = *(line + i);
        if (character > 64 && character < 91)
        {
            *(line + i) = character + 32;
            total++;
        }
    }
    return total;
}

/* reduceSpace reduces all blank spaces to only a single blank space this applies to tabs as well
*
* line (char): the string to perform the operation
*/
int reduceSpace(char *line)
{
    int lineLength = strlen(line), w; 
    int totalSpacesRemoved = 0; 

    for (int i = 0; i < lineLength; i++)
    {

        if ((line[i] == ' ' && line[i + 1] == ' ') || line[i] == '\t')
        {
            totalSpacesRemoved++;
            w = i;
            while (w < lineLength)
            {
                line[w] = line[w + 1];
                i--;
                w++;
                
            }
        }
    }
    return totalSpacesRemoved;
}

/* replaceDigits changes all number to a blank space
*
* line (char): the string to perform the operation
*/
int replaceDigits(char *line)
{

    int lineLength = strlen(line);
    int character;
    int totalDigitsRemoved = 0;

    for (int i = 0; i < lineLength; i++)
    {
        character = line[i];
        /* Change all digits to a blank */
        if (character > 47 && character < 58)
        {
            line[i] = (57 - character) + character - 25;
            totalDigitsRemoved++;
        }
    }
    return totalDigitsRemoved;
}

/* replacePunc changes all punctuation to a blank space 
*
* line (char): the string to perform the operation
*/
int replacePunc(char *line)
{
    int lineLength = strlen(line);
    int character;
    int totalPuncRemoved = 0;

    for (int i = 0; i < lineLength; i++)
    {
        character = line[i];
        if ((character > 32 && character < 48) || (character > 57 && character < 65) || (character > 90 && character < 97) || (character > 122 && character <= 255))
        {
            line[i] = ' ';
            totalPuncRemoved++;
        }
    }
    return totalPuncRemoved;
}

/* trim removes any blank space at the beginning or end of the string
*
* line (char): the string to perform the operation
*/
int trim(char *line)
{
    int lineLength = strlen(line);
    int j = 0;
    int w = lineLength - 1;
    int totalTrimRemoved = 0;

    while (line[j] == ' ')
    {
        line[j] = 127;
        j++;
        totalTrimRemoved++;
    }
    while (line[w] == ' ')
    {
        line[w] = 127;
        w--;
        totalTrimRemoved++;
    }
    w = lineLength - 1;
    j = 0;

    if (line[w] == ' ' || line[j] == ' ')
    {
        printf("Error: The trim function within the findwords program was unable to complete its task. \n");
        return -1;
    }

    return totalTrimRemoved;
}
