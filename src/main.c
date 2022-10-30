#include "Compare.h"
#include "FileHandler.h"
#include "UI.h"

int main(int argc, char *argv[])
{
    FileContents leftFile = {0};
    FileContents rightFile = {0};

    readFile(argv[1], leftFile);
    readFile(argv[2], rightFile);

    // Stage 0

    // Comparison result = cmpContsStageZero(leftFile, rightFile);
    // displayResult(result);

    // Stage 1

    cmpContsStageOne(leftFile, rightFile);
    return 0;
}
