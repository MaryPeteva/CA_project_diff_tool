#include "FileHandler.h"


void readFile(const char *filePath, FileContents outContents)
{
    FILE *fileP;

    fileP = fopen(filePath, "r");

    if (fileP == NULL)
    {
        printf("Unable to open file");
        exit(0);
    }

    size_t i = 0;
    int size = ftell(fileP);
    if (size == 0)
    {
        outContents[i] = '\0';
    }
    while ((outContents[i] = fgetc(fileP)) != EOF)
    {
        i++;
    }

    fclose(fileP);
}