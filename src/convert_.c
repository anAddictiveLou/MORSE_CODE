#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define DECODE(x, y) \
    do { if (strcmp(str, x) == 0) {fputc(y, output); return 0;} } while (0);

int morseDecode(char *str, FILE* output)
{
    static int line = 1;
    if (strcmp(str, "\n") == 0) {fputc('\n', output);line++ ;return 0;} 

    DECODE(".-", 'a');
    DECODE("-...", 'b');
    DECODE("-.-.", 'c');
    DECODE("-..", 'd');
    DECODE(".", 'e');
    DECODE("..-.", 'f');
    DECODE("--.", 'g');
    DECODE("....", 'h');
    DECODE("..", 'i');
    DECODE(".---", 'j');
    DECODE("-.-", 'k');
    DECODE(".-..", 'l');
    DECODE("--", 'm');
    DECODE("-.", 'n');
    DECODE("---", 'o');
    DECODE(".--.", 'p');
    DECODE("--.-", 'q');
    DECODE(".-.", 'r');
    DECODE("...", 's');
    DECODE("-", 't');
    DECODE("..-", 'u');
    DECODE("...-", 'v');
    DECODE(".--", 'w');
    DECODE("-..-", 'x');
    DECODE("-.--", 'y');
    DECODE("--..", 'z');
    DECODE(".----", '1');
    DECODE("..---", '2');
    DECODE("...--", '3');
    DECODE("....-", '4');
    DECODE(".....", '5');
    DECODE("-....", '6');
    DECODE("--...", '7');
    DECODE("---..", '8');
    DECODE("----.", '9');
    DECODE("-----", '0');
    DECODE(".-.-.-", '.');
    DECODE("..--..", '?');
    DECODE("-....-", '-');
    DECODE("--..--", ',');
    DECODE("---...", ':');
    DECODE("........", '#');
    DECODE("/", ' ');
    fputc('*', output);
    printf("Error: Invalid Morse code %s on line %d.\n", str, line);
    return 1;
}   

void splitCharacter(char *str, FILE *output)
{
    char *p;
    //Tach chuoi lan dau tien
    p = strtok(str, " ");
    morseDecode(p, output);
    //Tach chuoi tu lan thu 2 tro
    //Su dung strok den khi NULL tra ve.
    while(p != NULL) {
        //Doi so NULL trong ham strtok de tiep tuc tach chuoi ban dau.
        p = strtok(NULL, " ");
        if (p != NULL) {
            morseDecode(p, output);
        }
    }
}

char *morseEncode(char l)
{
    static int line1 = 1;
    switch (l) 
    {
        case 'a':
            return ".- ";
        case 'b':
            return "-... ";
        case 'c':
            return "-.-. ";
        case 'd':
            return "-.. ";
        case 'e':
            return ". ";
        case 'f':
            return "..-. ";
        case 'g':
            return "--. ";
        case 'h':
            return ".... ";
        case 'i':
            return ".. ";
        case 'j':
            return ".--- ";
        case 'k':
            return "-.- ";
        case 'l':
            return ".-.. ";
        case 'm':
            return "-- ";
        case 'n':
            return "-. ";
        case 'o':
            return "--- ";
        case 'p':
            return ".--. ";
        case 'q':
            return "--.- ";
        case 'r':
            return ".-. ";
        case 's':
            return "... ";
        case 't':
            return "- ";
        case 'u':
            return "..- ";
        case 'v':
            return "...- ";
        case 'w':
            return ".-- ";
        case 'x':
            return "-..- ";
        case 'y':
            return "-.-- ";
        case 'z':
            return "--.. ";
        case '1':
            return ".---- ";
        case '2':
            return "..--- ";
        case '3':
            return "...-- ";
        case '4':
            return "....- ";
        case '5':
            return "..... ";
        case '6':
            return "-.... ";
        case '7':
            return "--... ";
        case '8':
            return "---.. ";
        case '9':
            return "----. ";
        case '0':
            return "----- ";
        case ' ':
            return "/ ";
        case '\n':
            line1++;
            return "\n";
        default:
            if (l != -1){printf("Error: Unrecognised character %c on line %d.\n", l, line1);}
            return "";
    }
}