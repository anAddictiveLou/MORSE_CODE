#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "convert_.h"

int existsDetect(char *fname) 
{
    FILE *pFile = NULL; 
    pFile = fopen(fname, "r");
    if (pFile != NULL) {
        fclose(pFile);
        return 1;
    } return 0;
}

int fileDetect(FILE *pFile) 
{
    char c = -2;
    do
    {
        c = fgetc(pFile);
    } while (((c == '.') || (c == '-') || (c == '/') || (c == ' ')) || (c == '\n'));
    if (c != EOF) {
        rewind(pFile);
        return 0;   //character file
    }
    rewind(pFile); 
    return 1;       //morse file
}

int convertToCharacter(FILE *input, FILE *output)  //output is character file.
{   
    char buff[300];
    char ch;
    size_t i = 0;
    
    while ((ch = fgetc(input)) != EOF) 
    {
        switch (ch)
        {
        case '\n':
            buff[i] = ' ';
            buff[i+1] = '\n';
            buff[i+2] = ' ';
            i+=3;
            break;
        
        default:
            buff[i] = ch;
            i++;
            break;
        }
    }
    splitCharacter(buff, output);    
    return 0;
}

int convertToMorse(FILE *input, FILE *ouput)   //output is morse file.
{
    int size = 0;
    char chr;
    do
    {           
        chr = fgetc(input);
        chr = tolower(chr);
        size++;
        fputs(morseEncode(chr), ouput);
        
    } while (chr != EOF);
    return 0;
}

