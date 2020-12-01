#include <stdio.h>


int main(int argc, char *argv[]) {
    switch(argc-1) {
        case 2:
            printf("you entered 1 argument\n");
            break;
        case 4:
            printf("you entered 2 argument\n");
            break;
        case 5:
            printf("you entered 1 argument\n");
            break;
        default:
            printf("Not a valid ");
    }

    return 0;
}
