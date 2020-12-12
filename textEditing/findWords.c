#include "textProc.h"

#define MAXSIZE 500   /* maximum size of input line */
#define MAXWORDS 1000 /* maximum number of unique words */

int main(int argc, char *argv[])
{

   char line[MAXSIZE];
   char response[1] = "Y";
   struct Performance *performance = newPerformance();

   while (response[0] != 'N')
   {
      printf("\nEnter Input\n->");
      fgets(line, MAXSIZE, stdin);

      printf("\nInput text before: %s\n", line);
      applyAllTextOps(line, performance);
      printStats(performance);
      printf("\nInput text after: %s\n", line);

      printf("\nType \"N\" to exit the program\n->");
      fgets(response, MAXSIZE, stdin);
      printf("\n");
   }
   free(performance);
   return (0);
}
