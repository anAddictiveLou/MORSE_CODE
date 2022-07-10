#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "file_.h"
#include "convert_.h"

#define ERR(x) do {printf("Error: %s could not be opened.\n", argv[x]); exit(EXIT_FAILURE); \
} while (0);

int main(int argc, char *argv[])
{
   if (argc != 3) {
      printf("Usage: morse <input file> <output file>\n");
      exit(EXIT_FAILURE);
   }  

   int test = existsDetect(argv[2]); 
   char ch;

   /*Mo file input va kiem tra loi*/
   FILE *input = NULL;
   input = fopen(argv[1],"r");
   if (input == NULL){ERR(1)};

   int check = fileDetect(input);  

   if (test == 1) { //test = 1: file output da ton tai.

      switch (check) //Kiem tra file input la loai file nao.
      {
      case 1:  //input file la file Morse.
         printf("Warning: FILENAME already exists. Do you wish to overwrite (y,n)? ");
         scanf("%c", &ch);
         if (ch == 'y') {
         /*Mo file output va kiem tra loi*/
         FILE *output = NULL;
         output = fopen(argv[2], "w+");
         if (output == NULL){ERR(2)};

         convertToCharacter(input, output);
         fclose(output);
         }
         fclose(input);
         break;   

      case 0:  //input file la file Character.
         printf("Warning: FILENAME already exists. Do you wish to overwrite (y,n)? ");
         scanf("%c", &ch);
         if (ch == 'y') {
         /*Mo file output va kiem tra loi*/
         FILE *output = NULL;
         output = fopen(argv[2], "w+");
         if (output == NULL){ERR(2)};

         convertToMorse(input, output);
         fclose(output);
         }
         fclose(input);
         break;
      }

   } else if (test == 0) { //test = 0: file output chua ton tai, tao file output.

      FILE *output = NULL;
      switch (check) //Kiem tra file input la loai file nao.
      {
      case 1:   //input file la file Morse.
         output = fopen(argv[2], "w");
         if (output == NULL){ERR(2)};
         convertToCharacter(input, output);
         fclose(input);
         fclose(output);
         break;   

      case 0:   //input file la file Morse.
         output = fopen(argv[2], "w");
         if (output == NULL){ERR(2)};
         convertToMorse(input, output);
         fclose(input);
         fclose(output);
         break;
      }
   } 
   return 0;
}
