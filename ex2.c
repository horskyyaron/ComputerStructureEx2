#include <stdio.h>
#include <stdbool.h>
#include <string.h>


const int SRC_ARG = 1;
const int DST_ARG = 2;
const int SRC_OS_ARG = 3;
const int DST_OS_ARG = 4;
const int ENDIANNESS_ARG = 5;
const int MIN_FILE_NAME_SIZE = 4;

bool isTextFile(char* argument) {
    //check if a given argument is a text file.
    int argLength = strlen(argument);

    //minimum length for file name is 4 ("X.txt").
    if (argLength >= MIN_FILE_NAME_SIZE) {

        //slicing the argument string and getting the last four chars.
        char *argSuffix = argument + (argLength - 4) * sizeof(char);

        const char *txtSuffix = ".txt";

        //checks if the end of the file argument has ".txt" in the end.
        return (strcmp(argSuffix, txtSuffix) == 0);
    } else {
        return false;
    }
}


//this function will create a copy of a given txt file.
void copy(char *srcFile, char *dstFile) {
    if(isTextFile(srcFile) && isTextFile(dstFile)) {
        FILE *src;
        FILE *dst;

        src = fopen(srcFile, "rb");
        if(src != NULL) {
             n
        }
    }

}

void osSensitiveCopy(char *srcFile, char *dstFile, char *srcOs, char *dstOs, char *endianness) {
    if(endianness != NULL) {
        printf("5 arguments scenario");
    } else {
        printf("4 arguments scenario");
    }
}

int main(int argc, char *argv[]) {

    int numOfArguments = argc - 1;

    switch(numOfArguments) {
        case 2: {
            copy(argv[SRC_ARG], argv[DST_ARG]);
            break;
        }
        case 4: {
            osSensitiveCopy(argv[SRC_ARG], argv[DST_ARG], argv[SRC_OS_ARG], argv[DST_OS_ARG], NULL);
            break;
        }
        case 5: {
            osSensitiveCopy(argv[SRC_ARG], argv[DST_ARG], argv[SRC_OS_ARG], argv[DST_OS_ARG], argv[ENDIANNESS_ARG]);
            break;
        }
        default: {
            printf("Please enter a correct number of arguments.\n");
        }
    }

    return 0;
}
