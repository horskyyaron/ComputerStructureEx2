#include <stdio.h>
#include <stdbool.h>
#include <string.h>


const int SRC_ARG = 1;
const int DST_ARG = 2;
const int SRC_OS_ARG = 3;
const int DST_OS_ARG = 4;
const int ENDIANNESS_ARG = 5;
const int MIN_FILE_NAME_SIZE = 4;

const int BIG_ENDIAN = 0;
const int LITTLE_ENDIAN = 1;
const int LITTLE_ENDAIN_BOM = 0xFF;

//            //checks the endianness of the file, by checking the first BOM byte. FF = little endian, FE = big endian.
//            int endianness = (*buffer == LITTLE_ENDAIN_BOM) ? LITTLE_ENDIAN : BIG_ENDIAN;
//






//for readability for now.
bool isTextFile(char* argument);
void copy(char *srcFilePath, char *dstFilePath);


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
void copy(char *srcFilePath, char *dstFilePath) {
    if(isTextFile(srcFilePath) && isTextFile(dstFilePath)) {
        //FILE pointers to the source and destination files.
        FILE *srcFile = fopen(srcFilePath, "rb");
        FILE *dstFile = fopen(dstFilePath, "wb");

        //check that the source file was opened successfully.
        if(srcFile != NULL) {

            //the buffer will hold each char read from the src file. (UTF-16, each char will be 2 bytes long).
            unsigned char buffer[2];

            //reading the first char.
            size_t elementsRead = fread(buffer, sizeof(buffer),1,srcFile);

            //as long as chars are being read, continue to read the src file.
            while(elementsRead != 0) {
                //copying (writing) the read char to the destination file.
                fwrite(buffer, sizeof(buffer),1,dstFile);
                //read the next char.
                elementsRead = fread(buffer, sizeof(buffer),1,srcFile);
            }

        }
    }

}