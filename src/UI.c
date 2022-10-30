#include "UI.h"
void displayResult(Comparison result)
{
    if (result == true)
    {
        printf("Files are identical.\n");
    }

    else
    {
        printf("Files are different.\n");
    }
}