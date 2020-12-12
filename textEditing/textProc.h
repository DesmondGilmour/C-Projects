#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Performance
{
    unsigned int chopNum;
    unsigned int lowerCaseNum;
    unsigned int reduceSpaceNum;
    unsigned int replaceDigitsNum;
    unsigned int replacePuncNum;
    unsigned int trimNum;
};


void applyAllTextOps(char *line, struct Performance *performance);
void printStats(struct Performance *performance);
struct Performance *newPerformance();
