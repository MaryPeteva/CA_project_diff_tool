#include "Compare.h"

Comparison cmpContsStageZero(FileContents leftFile, FileContents rightFile)
{
    if (strlen(leftFile) != strlen(rightFile))
    {
        return false;
    }

    size_t index = 0;

    while (leftFile[index] != '\0' && rightFile[index] != '\0')
    {
        if (leftFile[index] != rightFile[index])
        {
            return false;
        }
        index++;
    }

    return true;
}


void cmpContsStageOne(FileContents leftFile, FileContents rightFile)
{
    int line_mistakes[200] = {0};
    int line_marker = 0;
    long unsigned int size = 0;
    int lSize = strlen(leftFile);
    int rSize = strlen(rightFile);

    if (lSize >= rSize)
    {
        size = lSize;
    }

    else
    {
        size = rSize;
    }

    size_t Lindex;
    size_t rIndex;

    for (Lindex = 0, rIndex = 0; Lindex < size || rIndex < size; Lindex++, rIndex++)
    {

        if (leftFile[Lindex] != rightFile[rIndex])
        {
            line_mistakes[line_marker]++;
        }
        if (leftFile[Lindex] == '\n' && rightFile[rIndex] == '\n')
        {
            line_marker++;
            // line_mistakes[line_marker] = 0;
        }
        else if (leftFile[Lindex] == '\n' && rightFile[rIndex] != '\n')
        {
            while (rightFile[rIndex] != '\n')
            {
                rIndex++;
            }
            line_mistakes[line_marker]++;
            line_marker++;
        }
        else if (leftFile[Lindex] != '\n' && rightFile[rIndex] == '\n')
        {
            while (leftFile[Lindex] != '\n')
            {
                Lindex++;
            }
            line_mistakes[line_marker]++;
            line_marker++;
        }
    }

    int differ = 0;
    for (size_t i = 0; i < line_marker; i++)
    {
        if (line_mistakes[i] > 0)
        {
            differ++;
        }
    }

    if (differ == 1)
    {
        printf("%d line differs.\n", differ);
    }
    else if (differ > 1)
    {
        printf("%d lines differ.\n", differ);
    }
    else
    {
        printf("Files are identical.\n");
    }
}