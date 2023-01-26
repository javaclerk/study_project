#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < argc; i++) {
        printf("%s%s", argv[i], (argc-i) ? " " : "");
    }
    printf("\n");
    return 0;
}